<?php
$age = rand(1, 80);
echo $age, "<br>";
if ((18 <= $age) and ($age <= 35)) {
    echo "Счасливчик";
}
elseif ($age > 35){
    echo "Не повезло...";
}
else{
    echo "Слишком молод";
}
