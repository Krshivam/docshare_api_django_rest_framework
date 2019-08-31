from django.db import models
from django.contrib.auth.models import User
import os
import hashlib
from django.core.files.storage import FileSystemStorage
# Create your models here.

class MediaFileSysytemStorage(FileSystemStorage):
	def _save(self,name,content):
		print(name)
		if self.exists(name):
			return name
		#print("Hello")
		return super(MediaFileSysytemStorage,self)._save(name,content)

def media_file_name(instance,filename):
	h = instance.md5sum
	basename ,ext = os.path.splitext(filename)
	return os.path.join('mediafiles',h[0:1],h[1:2],h+ext.lower())



class UploadFile(models.Model):
	file = models.FileField(blank=False, null=False,upload_to=media_file_name,storage=MediaFileSysytemStorage())
	description = models.CharField(max_length=100)
	uploaded_at = models.DateTimeField(auto_now_add=True)
	owner = models.ForeignKey(User, related_name='owner', on_delete=models.CASCADE)
	file_name = models.CharField(max_length=200)
	md5sum = models.CharField(max_length=36)
	def save(self,*args,**kwargs):
		if not self.pk:
			md5 = hashlib.md5()
			for chunk in self.file.chunks():
				md5.update(chunk)
			self.md5sum = md5.hexdigest()
			print(self.md5sum)
		super(UploadFile,self).save(*args,**kwargs)

class SharedFiles(models.Model):
	parent = models.ForeignKey(User,related_name='parent',on_delete=models.CASCADE)
	received = models.ForeignKey(User,related_name='recieved_user',on_delete=models.CASCADE)
	md5value = models.CharField(max_length=200)
	sharing_to = models.EmailField()
	link = models.URLField()
	#file = models.CharField(max_length=100,blank=False)


