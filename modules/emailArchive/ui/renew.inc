<?php
$EID=$_GET['eid'];
$EXP=$_GET['exp'];

$servername = "localhost";
$username = "root";
$password = "";
$dbname = "based";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
$sql = "UPDATE ems_email SET ems_email.expire_at='$EXP' WHERE ems_email.id='$EID'";
$result = $conn->query($sql);
echo $EXP;
$conn->close();
?>
