<?php

include_once UTILITY.'class.util.inc';
//include_once COMMON.'class.common.cca.inc';
//include_once './common/class.common.cca.inc';
include_once MODULES_CCA.'bao/class.ccabao.inc';
$_CCABAO = new CCABAO();
$_DB = DBUtil::getInstance();
$globalUser;
if(isset($_POST['saveRQST'])){

	$ccaClass = new CCA();
	$_cca = new CCA();

	//$ccaClass->setCatID($_POST['txtQuestion']);
	$ccaClass->setCat($_POST['Category']);
	$ccaClass->setActivityName($_POST['Activity']);
	$ccaClass->setOrganizer($_POST['Organizer']);
	$ccaClass->setVenu($_POST['venu']);
	$ccaClass->setDescription($_POST['Description']);
	$ccaClass->setDate($_POST['Date']);
	$ccaClass->setTime($_POST['Time']);

	$_CCABAO->AddCatagory($ccaClass);

	header("Location:".PageUtil::$CCA);

	//$_CCABAO->Adddetails($ccaClass);
}
if(isset($_GET['reject']))
{

 //reading the Role object from the result object
header("Location:".PageUtil::$CCA);
	//Sheader("Location:".PageUtil::$ROLE);
}
if(isset($_GET['del']))
{

	$CCA = new CCA();
	$CCA->setsrl($_GET['del']);
	$_CCABAO->CCADELETE($CCA); //reading the Role object from the result object
	header("Location:".PageUtil::$CCA);

	//Sheader("Location:".PageUtil::$ROLE);
}


/* reading an existing Role information */
if(isset($_GET['edit']))
{
	$cca = new CCA();
	$cca->setsrl($_GET['edit']);
	$globalUser = $_CCABAO->readcca($cca)->getResultObject(); //reading the Role object from the result object
	//echo $globalUser->getCat();
}
if(isset($_POST['update'])){

	$ccam = new CCA();


	$ccam->setsrl($_GET['edit']);
	$ccam->setCat($_POST['Category']);
	$ccam->setActivityName($_POST['Activity']);
	$ccam->setOrganizer($_POST['Organizer']);
	$ccam->setVenu($_POST['venu']);
	$ccam->setDescription($_POST['Description']);
	$ccam->setDate($_POST['Date']);
	$ccam->setTime($_POST['Time']);

	$_CCABAO->updatecat($ccam);
	header("Location:".PageUtil::$CCA);

}
function isCatagoryAvailable($cats)
{


	for ($i=0; $i < sizeof($cats); $i++) {
		# code...
		if(!strcasecmp($cats[$i]->getCat())){
			return true;
		}
	}

	return false;
}


?>
