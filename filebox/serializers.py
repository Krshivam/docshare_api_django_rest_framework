from rest_framework import serializers
from .models import UploadFile,SharedFiles
from django.contrib.auth.models import User
from rest_framework.validators import UniqueValidator
from django.core.mail import EmailMessage

class RegistrationSerializer(serializers.ModelSerializer):
	username = serializers.CharField(required=True,validators=[UniqueValidator(queryset=User.objects.all())])
	email = serializers.EmailField(required=True,validators=[UniqueValidator(queryset=User.objects.all())])
	password = serializers.CharField(style={'input_type': 'password'},write_only=True)
	password2 = serializers.CharField(style={'input_type': 'password'},write_only=True)
	def create(self,validated_data):
		user = User.objects.create_user(validated_data['username'],validated_data['email'])
		password = self.validated_data['password']
		password2 = self.validated_data['password2']
		if password2!=password:
			raise serializers.ValidationError({'password':'Passwords do not match'})
		user.set_password(password)
		user.save()
		return user

	class Meta:
		model=User
		fields = ['username','email','password','password2']


class UserSerializer(serializers.ModelSerializer):
	class Meta:
		model = User
		fields = ['id', 'username']

class UploadFileSerializer(serializers.ModelSerializer):
	owner = serializers.ReadOnlyField(source='owner.username')
	md5sum = serializers.SerializerMethodField()
	pk = serializers.SerializerMethodField
	class Meta:
		model = UploadFile
		fields = ['file','description','owner','md5sum','pk']
	def get_md5sum(self,obj):
		return obj.md5sum
	def get_pk(self,obj):
		return obj.pk

class SharingSerializer(serializers.ModelSerializer):
	class Meta:
		model = SharedFiles
		fields = ['md5value','link']

class ShareFileSerializer(serializers.ModelSerializer):
	sharing_to = serializers.EmailField(required=True)
	md5value = serializers.CharField(required=True)
	def create(self,validated_data):
		serializer_class = UploadFileSerializer
		current_user = self.context['request'].user
		email=self.validated_data['sharing_to']
		md5value=self.validated_data['md5value']
		if not User.objects.filter(email=email).exists():
			raise serializers.ValidationError({'Email':'Email do not match'}) 
		if not UploadFile.objects.filter(md5sum=md5value):
			raise serializers.ValidationError({'description':'document do not match'})
		if UploadFile.objects.filter(md5sum=md5value):
			file_object_owner = UploadFile.objects.filter(md5sum=md5value)
			if not file_object_owner.filter(owner=current_user).exists():
				raise serializers.ValidationError({'description':'document do not match'})
		user_id = User.objects.get(email=email).pk
		shared_user = User.objects.get(pk=user_id)
		parent = User.objects.get(username=current_user)
		file_id = UploadFile.objects.get(md5sum=md5value)
		name = file_id.file.name
		name1 = '127.0.0.1:8000/media/'+str(name)
		sharefile = SharedFiles(parent=parent,received=shared_user,sharing_to=email,md5value=md5value,link=name1)
		sharefile.save()
		
		#print(type(current_user))
		subject = str(current_user)+' shared a document with you.'
		#print(to_email)
		message = "127.0.0.1:8000/media/"+str(name)
		email_ = EmailMessage(subject,message,to=[email])
		email_.send()
		return sharefile
		
	class Meta:
		model = SharedFiles
		fields = ['sharing_to','md5value']



