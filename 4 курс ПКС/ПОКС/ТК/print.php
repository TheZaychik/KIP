<?php
$link = mysqli_connect("127.0.0.1", "root", "root", "phpPoks");
if (!$link)
    die("Error");
else
    echo "Соединение установлено! Инфо: <br> " . mysqli_get_client_info() . "<br>" . mysqli_get_host_info($link) . "<br>";
$query = "SELECT * FROM books";
$result = mysqli_query($link, $query);
if (!$result) echo "Произошла ошибка: " . mysqli_error($link) . "<br>";
else echo "Данные получены:<br>";
while ($row = $result->fetch_assoc()) {
    echo "--------------<br>";
    echo "Книга: {$row['book']} <br>";
    echo "Жанр: {$row['genre']} <br>";
    echo 'Свойства:', "<br>";
    echo "Иллюстрации: {$row['Illustrations']} <br>";
    echo "Тв. переплет: {$row['HardCover']} <br>";
    echo "Для детей: {$row['ForChildren']} <br>";
}
mysqli_close($link);