from django.db import models
from django.contrib.auth.models import User


# Create your models here.

class PlayerScore(models.Model):
    user = models.OneToOneField(to=User, on_delete=models.CASCADE)
    UserScore = models.IntegerField(verbose_name='Очки игрока', default='0')



