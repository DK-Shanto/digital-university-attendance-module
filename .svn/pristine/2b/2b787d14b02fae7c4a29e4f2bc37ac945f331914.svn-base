<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_SCHOLARSHIP.'bao/class.cocurricular_bao.inc';



$_CocurricularBAO = new CocurricularBAO();
$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();


$globalCocurricular = '';


// saving a new Cocurricular details
if(isset($_POST['save']))
{
	$Cocurricular = new Cocurricular();	

	$Cocurricular->setCocurricularName($_DB->secureInput($_POST['txtName'])); 
	$Cocurricular->setShortName($_DB->secureInput($_POST['txtShortCode']));

	$Result = $_CocurricularBAO->newCocurricularRequest($Cocurricular);		

	if($Result->getIsSuccess()){
	   Util::printToast($Result->getResultObject());	
	}
}

if(isset($_GET['del'])){
	$Cocurricular = new Cocurricular();	
	$Cocurricular->setID($_GET['del']);	
	$Result = $_CocurricularBAO->deleteCocurricular($Cocurricular); //reading the user object from the result object

	if($Result->getIsSuccess()){
	   Util::printToast($Result->getResultObject());	
	}

	header("Location:".PageUtil::$SCHOLARSHIP_COCURRICULAR);
} 

if(isset($_GET['edit'])){
	$Cocurricular = new Cocurricular();	
	$Cocurricular->setID($_GET['edit']);	

	$globalCocurricular = $_CocurricularBAO->readCocurricular($Cocurricular)->getResultObject(); 
	//reading the Cocurricular object from the result object
}

if(isset($_POST['update'])){
	$Cocurricular = new Cocurricular();

	$Cocurricular->setID($_GET['edit']);
	$Cocurricular->setCocurricularName($_DB->secureInput($_POST['txtName'])); 
	$Cocurricular->setShortName($_DB->secureInput($_POST['txtShortCode']));

	$Result = $_CocurricularBAO->updateCocurricular($Cocurricular);

	if($Result->getIsSuccess()){
	   Util::printToast($Result->getResultObject());	
	}

	header("Location:".PageUtil::$SCHOLARSHIP_COCURRICULAR);
}

?>