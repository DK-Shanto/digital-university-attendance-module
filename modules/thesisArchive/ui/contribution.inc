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

$sql = "UPDATE tms_student_thesis SET tms_student_thesis.contribution='$ConVal' WHERE tms_student_thesis.thesis_id='$PID' AND tms_student_thesis.student_id='$UID'";
$result = $conn->query($sql);
echo $ConVal;
$conn->close();
?>
