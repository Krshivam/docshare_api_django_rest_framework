from django.urls import path
from filebox import views
from rest_framework.urlpatterns import format_suffix_patterns

urlpatterns =[
	path('files/',views.UploadedFilesList.as_view()),
	path('file/<int:pk>/',views.UploadedFileDetail.as_view()),
	path('users/', views.UserList.as_view()),
	#path('users/<int:pk>/', views.UserDetail.as_view()),
	path('received/',views.ReceivedFiles.as_view()),
	path('register/',views.UserRegistration.as_view()),
	path('share/',views.ShareFile.as_view())
]

urlpatterns = format_suffix_patterns(urlpatterns)