from django.shortcuts import render
from django.http import HttpResponse, JsonResponse,Http404
from django.views.decorators.csrf import csrf_exempt
from rest_framework.decorators import api_view
from rest_framework.parsers import JSONParser
from filebox.models import UploadFile,SharedFiles
from filebox.serializers import UploadFileSerializer,UserSerializer,RegistrationSerializer,ShareFileSerializer,SharingSerializer
from rest_framework.response import Response
from rest_framework import status
from rest_framework.views import APIView
from rest_framework import generics
from django.contrib.auth.models import User
from rest_framework import permissions
from django.core.mail import EmailMessage
from itertools import chain

#using mixins

class UploadedFilesList(generics.ListCreateAPIView):
	serializer_class = UploadFileSerializer
	permission_classes = [permissions.IsAuthenticated]
	def perform_create(self, serializer):
		serializer.save(owner=self.request.user)
	def get_queryset(self):
		user = self.request.user
		return UploadFile.objects.filter(owner=user)
	
class ReceivedFiles(generics.ListAPIView):
	serializer_class = SharingSerializer
	permission_classes = [permissions.IsAuthenticated]
	def get_queryset(self):
		user = self.request.user
		return SharedFiles.objects.filter(received=user)

class UploadedFileDetail(generics.RetrieveUpdateDestroyAPIView):
	serializer_class = UploadFileSerializer
	permission_classes = [permissions.IsAuthenticated]
	def get_queryset(self):
		user = self.request.user
		return UploadFile.objects.filter(owner=user)

class UserList(generics.ListAPIView):
	queryset = User.objects.all()
	serializer_class = UserSerializer

class UserDetail(generics.RetrieveAPIView):
	queryset = User.objects.all()
	serializer_class = UserSerializer

class UserRegistration(generics.CreateAPIView):
	serializer_class = RegistrationSerializer

class ShareFile(generics.CreateAPIView):
	permission_classes = [permissions.IsAuthenticated]
	serializer_class = ShareFileSerializer



