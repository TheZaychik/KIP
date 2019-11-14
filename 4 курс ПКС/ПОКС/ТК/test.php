<form class="form-signin" method="POST">
  <h2>Login</h2>
  <input type="text" name="username" class="form-contol" placeholder="Username" required><br />
  <input type="text" name="password" class="form-contol" placeholder="Password" required><br />
  <button type="submit">Login</button>
  
</form>


<?php
$host = 'localhost'; // адрес сервера
$database = 'db1'; // имя базы данных
$user = 'admin'; // имя пользователя
$password = 'admin'; // пароль
 
$link = mysqli_connect($host, $user, $password, $database) 
    or die("Ошибка " . mysqli_error($link));

if (isset($_POST['username']) and isset($_POST['password'])) {
    $username = $_POST['username'];
    $password = $_POST['password'];

echo "Значения переменных, переданных методом POST - $username и $password";
    
if ($result = mysqli_query($link, "SELECT username FROM users WHERE username='{$username}'")) {
    printf("Select вернул %d строк.\n", mysqli_num_rows($result));
}
if ($result != 0) {
    $_SESSION['username'] = $username;
} else {
    $fsmg = "Ошибка";
}

  if (isset($_SESSION['username'])) {
    $username = $_SESSION['username'];
    echo "Hello"  . $username . "";
    echo "Вы вошли"; 
    echo "<a href='logout.php'></a>";
}
}


?>
