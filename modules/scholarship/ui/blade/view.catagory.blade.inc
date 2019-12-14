<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_SCHOLARSHIP.'bao/class.catagory_bao.inc';



$_CatagoryBAO = new CatagoryBAO();
$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();


$globalCatagory = '';


// saving a new catagory details
if(isset($_POST['save']))
{
	$Catagory = new Catagory();	

	$Catagory->setCatagoryName($_DB->secureInput($_POST['txtName'])); 
	$Catagory->setShortName($_DB->secureInput($_POST['txtShortCode']));

	$Result = $_CatagoryBAO->newCatagoryRequest($Catagory);		

	if($Result->getIsSuccess()){
	   Util::printToast($Result->getResultObject());	
	}
}

if(isset($_GET['del'])){
	$Catagory = new Catagory();	
	$Catagory->setID($_GET['del']);	
	$Result = $_CatagoryBAO->deleteCatagory($Catagory); //reading the user object from the result object

	if($Result->getIsSuccess()){
	   Util::printToast($Result->getResultObject());	
	}

	header("Location:".PageUtil::$SCHOLARSHIP_TYPE);
} 

if(isset($_GET['edit'])){
	$Catagory = new Catagory();	
	$Catagory->setID($_GET['edit']);	

	$globalCatagory = $_CatagoryBAO->readCatagory($Catagory)->getResultObject(); 
	//reading the catagory object from the result object
}

if(isset($_POST['update'])){
	$Catagory = new Catagory();

	$Catagory->setID($_GET['edit']);
	$Catagory->setCatagoryName($_DB->secureInput($_POST['txtName'])); 
	$Catagory->setShortName($_DB->secureInput($_POST['txtShortCode']));

	$Result = $_CatagoryBAO->updateCatagory($Catagory);

	if($Result->getIsSuccess()){
	   Util::printToast($Result->getResultObject());	
	}

	header("Location:".PageUtil::$SCHOLARSHIP_TYPE);
}

?>