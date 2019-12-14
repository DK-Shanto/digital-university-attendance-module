<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_BOOK.'bao/class.book_own_list_bao.inc';


$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();
$_BookListBAO = new BookListBAO();
$globalBook = new Book();
if(isset($_GET['edit']))
{
  $globalBook->setBookID($_GET['edit']);
  $globalBook = $_BookListBAO->readBookPositions($globalBook)->getResultObject();
  //echo "".$globalBook->getTitle()."";
  //header("Location:".PageUtil::$BOOK_EDIT."? globalBook=".$globalBook);

}

if(isset($_POST['update']))
{

//  echo "string";
  $Book = new Book();

  $Book->setBookID($_DB->secureInput($globalBook->getBookID()));

	$Book->setTitle($_DB->secureInput($_POST['txtBookTitle']));

	$Book->setEdition($_DB->secureInput($_POST['txtBookEdition']));

	$Book->setWritter($_DB->secureInput($_POST['txtWritter']));

	$Book->setDescription($_DB->secureInput($_POST['txtDescription']));

	$Book->setAmmount($_DB->secureInput($_POST['txtAmmount']));

	$Book->setContactNumber($_DB->secureInput($_POST['txtContactNumber']));

  $_BookListBAO->updateBookRequest($Book);

  header("Location:".PageUtil::$BOOK_OWN_LIST);
}

if(isset($_GET['delete']))
{
  $Book = new Book();
  $Book->setBookID($_GET['delete']);
  $_BookListBAO->deleteBook($Book);
  header("Location:".PageUtil::$BOOK_OWN_LIST);
}

?>
