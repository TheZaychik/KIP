from django import forms
from django import forms
from main.models import PlayerScore
from django.contrib.auth.forms import UserCreationForm, UserChangeForm
from django.contrib.auth.models import User


class FormReg(UserCreationForm):
    class Meta:
        model = User
        fields = ['email', 'username', 'password1', 'password2']


class CustomUserForm(forms.ModelForm):
    class Meta:
        model = PlayerScore
        fields = ['UserScore']
