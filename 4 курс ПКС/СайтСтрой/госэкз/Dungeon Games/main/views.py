from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.decorators import login_required
from django.shortcuts import render, redirect
from main import forms
from main import models


def rates(request):
    userList = models.User.objects.all()
    scoreList = []
    for u in userList:
        scoreList.append(
            'Никнейм: ' + u.username + '<br> Кол-во очков: ' + str(models.PlayerScore.objects.get(user_id=u.id).UserScore))
    return render(request, 'rates.html', context={'scoreList': scoreList})


@login_required(login_url='/auth/')
def home(request):
    if request.method == 'POST':
     ps = models.PlayerScore.objects.all().filter(user_id=request.user.id).get()
     if ps.UserScore < int(request.POST['score']):
        ps.UserScore = int(request.POST['score'])
        ps.save()
    return render(request, 'home.html', context={'username': request.user.username})


@login_required(login_url='/auth/')
def log_out(request):
    logout(request)
    return redirect('/')


def auth(request):
    if request.method == 'POST':
        user = authenticate(username=request.POST['username'], password=request.POST['password'])
        if user is not None:
            login(request, user)
            return redirect('/')
        else:
            return render(request, 'auth.html', context={'err': 'Ошибка входа'})
    return render(request, 'auth.html')


def register(request):
    if request.method == 'POST':
        formUser = forms.FormReg(request.POST)
        if formUser.is_valid():
            formUser.save()
        else:
            return render(request, 'reg.html', context={'err': formUser.errors})
        playerScore = forms.PlayerScore(user=formUser.instance, UserScore=0)
        playerScore.save()
        user = authenticate(username=request.POST['username'], password=request.POST['password1'])
        login(request, user)
        return redirect('/')
    else:
        return render(request, 'reg.html')


def index(request):
    return render(request, 'index.html')
