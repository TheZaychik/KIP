<?php
$link = mysqli_connect("127.0.0.1", "root", "root", "phpPoks");
if (!$link)
    die("Error");
else
    echo "Соединение установлено! Инфо: <br> " . mysqli_get_client_info() . "<br>" . mysqli_get_host_info($link);
$query = 'CREATE TABLE users(
   			 login       VARCHAR(20),
   			 password    VARCHAR(20)
		)';


mysqli_close($link);
