Book<?php
ini_set('mysql.connect_timeout',300);
ini_set('default_socket_timeout',300);
include_once UTILITY.'class.util.inc';
include_once MODULES_BOOK.'bao/class.book_post_bao.inc';

$_BookBAO = new BookBAO();
$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();

$userID="";
$userID = $_SESSION["globalUser"];
$id = $userID->getID();

/* saving a new Book details*/
if(isset($_POST['request']))
{
	$Book = new Book();

	$con = mysqli_connect("localhost","root","");
	mysqli_select_db($con,"cseku");

	$qry = "SELECT * FROM ums_user WHERE '$id' = ums_user.ID";
	$result = mysqli_query($con,$qry);
	$res = mysqli_fetch_assoc($result);
	$user_name = "";
	$user_name = $res['FirstName']." ".$res['MiddleName']." ".$res['LastName'];
	$Book->setUserName($_DB->secureInput($user_name));

	$Book->setTitle($_DB->secureInput($_POST['txtBookTitle']));

	$Book->setEdition($_DB->secureInput($_POST['txtBookEdition']));

	$Book->setWritter($_DB->secureInput($_POST['txtWritter']));

	$Book->setDescription($_DB->secureInput($_POST['txtDescription']));

	$Book->setUserID($_DB->secureInput($userID->getID()));

	$Book->setAmmount(strtolower($_DB->secureInput($_POST['txtAmmount'])));

	$Book->setContactNumber($_DB->secureInput($_POST['txtContactNumber']));
	/// Image Start
	$UserID = $userID->getID();

	// $con = mysqli_connect("localhost","root","");
	// mysqli_select_db($con,"cseku");
	//
	// $qry = "SELECT * FROM bsms_book WHERE LOWER(bsms_book.name) LIKE LOWER('%".$search."%') ";
	// $res = mysqli_query($con,$qry);

	$con = mysqli_connect("localhost","root","");
	mysqli_select_db($con,"cseku");
	$filename = $_FILES['txtImage']['name'];
	$file_tmp = $_FILES['txtImage']['tmp_name'];
	$filetype = $_FILES['txtImage']['type'];
	$filesize = $_FILES['txtImage']['size'];
	for($i=0; $i<count($file_tmp); $i++){
		if(!empty($file_tmp[$i])){
			$name = addslashes($filename[$i]);
			$temp = addslashes(file_get_contents($file_tmp[$i]));
			$Date= date("Y-m-d");
			//echo $Date;
			$sql = "INSERT INTO bsms_book_image(id,date,name,image) values('$UserID','$Date'.'$name','$temp')";
			$res = mysqli_query($con,$sql);
		}
	}


	///$Book->setImageName($_DB->secureInput($name));
	///$Book->setImage($_DB->secureInput($image));

	/// Image End
  $Result = $_BookBAO->newBookRequest($Book);

	if($Result->getIsSuccess()){
	   Util::printToast($Result->getResultObject());
	}
}
?>
