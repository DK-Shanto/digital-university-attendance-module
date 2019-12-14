<?php

//insert.php

$connect = new PDO('mysql:host=localhost;dbname=testing', 'root', '');
echo $_POST["title"];
if(isset($_POST["title"]))
{
echo $_POST["title"];
 $query = "
 INSERT INTO events 
 (title, start_event, end_event, discipline) 
 VALUES (:title, :start_event, :end_event, :discipline)
 ";
 $statement = $connect->prepare($query);
 $statement->execute(
  array(
   ':title'  => $_POST['title'],
   ':start_event' => $_POST['start'],
   ':end_event' => $_POST['end'],
   ':discipline' => $_POST['discipline']
  )
 );
}


?>