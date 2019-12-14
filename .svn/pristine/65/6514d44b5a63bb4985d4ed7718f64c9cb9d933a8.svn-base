<?php

include_once UTILITY.'class.util.inc';

//include_once './common/class.common.cca.inc';
include_once MODULES_CCA.'bao/class.ccamenubao.inc';


$_CCAMENUBAO = new CCAMENUBAO();
$_DB = DBUtil::getInstance();
if(isset($_POST['addcat'])){

	$ccamenuClass = new CCAMENU();


	$ccamenuClass->setCatagory($_POST['Catagory']);

	$_CCAMENUBAO->AddmenuCatagory($ccamenuClass);
header("Location:".PageUtil::$CCAMENU);
}

if(isset($_GET['del']))
{

	$CCA = new CCAMENU();
	$CCA->setCatagory($_GET['del']);
	$CCA->setcatID($_GET['del']);
	$_CCAMENUBAO->CATDELETE($CCA); //reading the Role object from the result object
header("Location:".PageUtil::$CCAMENU);
	//Sheader("Location:".PageUtil::$ROLE);
}
if(isset($_GET['reject']))
{

 //reading the Role object from the result object
header("Location:".PageUtil::$CCAMENU);
	//Sheader("Location:".PageUtil::$ROLE);
}

/* reading an existing Role information */
if(isset($_GET['edit']))
{
	$cca = new CCAMENU();
	$cca->setCatagory($_GET['edit']);
	$cca->setcatID($_GET['edit']);
	$globalUser = $_CCAMENUBAO->readCAT($cca)->getResultObject(); //reading the Role object from the result object
}
if(isset($_POST['update'])){

	$ccam = new CCAMENU();


	$ccam->setCatagory($_POST['Catagory']);
	$ccam->setcatID($_GET['edit']);

	$_CCAMENUBAO->updatecategory($ccam);
	header("Location:".PageUtil::$CCAMENU);

}
?>
