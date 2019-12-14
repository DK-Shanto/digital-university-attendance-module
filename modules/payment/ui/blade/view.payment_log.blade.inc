<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_PAYMENT.'bao/class.paymentbao.inc';
$_PaymentBAO = new PaymentBAO();
$_DB = DBUtil::getInstance();
$result = NULL;
$result1 = NULL;
$result2 = NULL;
if(isset($_POST['search']))
{

	if(($_POST['selectedField'] == "Registration Fee"))
	{
		//student id
		$SID = $_POST['sid'];
		$RegistrationFee = new RegistrationFee();
		$RegistrationFee->setUniversityID($SID);
		$result = $_PaymentBAO->getRegistrationFeeBySid($RegistrationFee)->getResultObject();
	}


	else if(($_POST['selectedField'] == "Hall Fee"))
	{
		//student id
		$SID = $_POST['sid'];
		$HallFee = new HallFee();
		$HallFee->setUniversityID($SID);
		$result1 = $_PaymentBAO->getHallFeeBySid($HallFee)->getResultObject();
	}


		else if(($_POST['selectedField'] == "Others Fee"))
	{
		//student id
		$SID = $_POST['sid'];
		$OthersFee = new OthersFee();
		$OthersFee->setUniversityID($SID);
		$result2 = $_PaymentBAO->getOthersFeeBySid($OthersFee)->getResultObject();
	}
}
?>