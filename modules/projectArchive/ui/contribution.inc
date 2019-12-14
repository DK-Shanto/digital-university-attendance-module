<?php
$PID=$_GET['pid'];
$UID=$_GET['uid'];
$ConVal=$_GET['conval'];

$servername = "localhost";
$username = "root";
$password = "";
$dbname = "cseku";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "UPDATE pms_student_project SET pms_student_project.contribution='$ConVal' WHERE pms_student_project.project_id='$PID' AND pms_student_project.student_id='$UID'";
$result = $conn->query($sql);
echo $ConVal;
$conn->close();
?>
