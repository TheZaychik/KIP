<?php
$link = mysqli_connect("127.0.0.1", "root", "root", "phpPoks");
if (!$link)
    die("Error");
else
    echo "Соединение установлено! Инфо: <br> " . mysqli_get_client_info() . "<br>" . mysqli_get_host_info($link) . "<br>";
$query = "CREATE TABLE books(
    			book  VARCHAR(20),
    			genre    VARCHAR(20),
    			Illustrations INT(6),
    			HardCover INT(6),
    			ForChildren INT(6)
		)";
if (mysqli_query($link, $query)) echo "Таблица создана.<br>";
else echo "Таблица не создана: " . mysqli_error($link) . "<br>";

$book = $_POST['name'];
$genre = $_POST['genre'];
$Illustrations = 0;
$HardCover = 0;
$ForChildren = 0;
if (isset($_POST['Illustrations'])) {
    $Illustrations = $_POST['Illustrations'];
}
if (isset($_POST['HardCover'])) {
    $HardCover = $_POST['HardCover'];
}
if (isset($_POST['ForChildren'])) {
    $ForChildren = $_POST['ForChildren'];
}
$query = "INSERT INTO books (book, genre,Illustrations,HardCover,ForChildren) VALUE ('{$book}','{$genre}',{$Illustrations},{$HardCover},{$ForChildren})";
if (mysqli_query($link, $query)) echo "Книга добавлена.<br>";
else echo "Книга не добавлена: " . mysqli_error($link) . "<br>";
mysqli_close($link);