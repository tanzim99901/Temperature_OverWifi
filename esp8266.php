<?php
$Temp = isset($_POST["temperature"]) ? $_POST["temperature"] : "";
$Write="<p>Temperature : " . $Temp . " </p>";
//create an HTML file to display the data within
file_put_contents('sensor.html',$Write);
?>
