<?php

include_once UTILITY.'class.util.inc';

//include_once './common/class.common.cca.inc';
include_once MODULES_CCA.'bao/class.ccaorganizerbao.inc';

$_CCAORGANIZERBAO = new CCAORGANIZERBAO();
$_DB = DBUtil::getInstance();


if(isset($_POST['addorg'])){

	$ccamenuClass = new CCAORGANIZER();


	$ccamenuClass->setOrganizer($_POST['Organizer']);

	$_CCAORGANIZERBAO->AddOrganizer($ccamenuClass);
	header("Location:".PageUtil::$CCAORGANIZER);

}

if(isset($_GET['del']))
{

	$CCA = new CCAORGANIZER();
	$CCA->setidg($_GET['del']);
		$CCA->setOrganizer($_GET['del']);
	$_CCAORGANIZERBAO->ORGDELETE($CCA); //reading the Role object from the result object
	header("Location:".PageUtil::$CCAORGANIZER);

	//Sheader("Location:".PageUtil::$ROLE);
}
if(isset($_GET['reject']))
{

 //reading the Role object from the result object
header("Location:".PageUtil::$CCAORGANIZER);
	//Sheader("Location:".PageUtil::$ROLE);
}

/* reading an existing Role information */
if(isset($_GET['edit']))
{
	$cca = new CCAORGANIZER();
	$cca->setOrganizer ($_GET['edit']);
	$cca->setidg ($_GET['edit']);

	$globalUser = $_CCAORGANIZERBAO->readORG($cca)->getResultObject(); //reading the Role object from the result object
}
if(isset($_POST['update'])){

	$ccam = new CCAORGANIZER();


	$ccam->setOrganizer($_POST['Organizer']);
	$ccam->setidg($_GET['edit']);

	$_CCAORGANIZERBAO->updateorganizer($ccam);
	header("Location:".PageUtil::$CCAORGANIZER);

}
?>
