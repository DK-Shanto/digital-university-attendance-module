<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_SCHOLARSHIP.'bao/class.quota_bao.inc';



$_QuotaBAO = new QuotaBAO();
$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();


$globalQuota = '';


// saving a new Quota details
if(isset($_POST['save']))
{
	$Quota = new Quota();	

	$Quota->setQuotaName($_DB->secureInput($_POST['txtName'])); 
	$Quota->setShortName($_DB->secureInput($_POST['txtShortCode']));

	$Result = $_QuotaBAO->newQuotaRequest($Quota);		

	if($Result->getIsSuccess()){
	   Util::printToast($Result->getResultObject());	
	}
}

if(isset($_GET['del'])){
	$Quota = new Quota();	
	$Quota->setID($_GET['del']);	
	$Result = $_QuotaBAO->deleteQuota($Quota); //reading the user object from the result object

	if($Result->getIsSuccess()){
	   Util::printToast($Result->getResultObject());	
	}

	header("Location:".PageUtil::$SCHOLARSHIP_QUOTA);
} 

if(isset($_GET['edit'])){
	$Quota = new Quota();	
	$Quota->setID($_GET['edit']);	

	$globalQuota = $_QuotaBAO->readQuota($Quota)->getResultObject(); 
	//reading the Quota object from the result object
}

if(isset($_POST['update'])){
	$Quota = new Quota();

	$Quota->setID($_GET['edit']);
	$Quota->setQuotaName($_DB->secureInput($_POST['txtName'])); 
	$Quota->setShortName($_DB->secureInput($_POST['txtShortCode']));

	$Result = $_QuotaBAO->updateQuota($Quota);

	if($Result->getIsSuccess()){
	   Util::printToast($Result->getResultObject());	
	}

	header("Location:".PageUtil::$SCHOLARSHIP_QUOTA);
}

?>