from django.db import models

# Create your models here.


class Student(models.Model):
    name = models.CharField(max_length=20)
    age = models.IntegerField()
    college = models.CharField(max_length=50)
    address = models.CharField(max_length=50)

    


