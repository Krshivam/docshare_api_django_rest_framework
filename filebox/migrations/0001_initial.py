# Generated by Django 2.2 on 2019-08-31 06:03

from django.conf import settings
from django.db import migrations, models
import django.db.models.deletion
import filebox.models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
        migrations.swappable_dependency(settings.AUTH_USER_MODEL),
    ]

    operations = [
        migrations.CreateModel(
            name='UploadFile',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('file', models.FileField(storage=filebox.models.MediaFileSysytemStorage(), upload_to=filebox.models.media_file_name)),
                ('description', models.CharField(max_length=100)),
                ('uploaded_at', models.DateTimeField(auto_now_add=True)),
                ('file_name', models.CharField(max_length=200)),
                ('md5sum', models.CharField(max_length=36)),
                ('owner', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, related_name='owner', to=settings.AUTH_USER_MODEL)),
            ],
        ),
        migrations.CreateModel(
            name='SharedFiles',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('md5value', models.CharField(max_length=200)),
                ('sharing_to', models.EmailField(max_length=254)),
                ('link', models.URLField()),
                ('parent', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, related_name='parent', to=settings.AUTH_USER_MODEL)),
                ('received', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, related_name='recieved_user', to=settings.AUTH_USER_MODEL)),
            ],
        ),
    ]
