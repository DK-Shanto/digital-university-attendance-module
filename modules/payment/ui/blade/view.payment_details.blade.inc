<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_PAYMENT.'bao/class.paymentbao.inc';
$_PaymentBAO = new PaymentBAO();
$_DB = DBUtil::getInstance();
$getRegistrationFee = '';
$Type = $_GET['type'];
//payment id 
$PID = $_GET['pid'];
if ($Type == "Registration Fee") {
$RegistrationFee = new RegistrationFee();
$RegistrationFee->setID($PID);
$getRegistrationFee = $_PaymentBAO->getRegistrationFee($RegistrationFee)->getResultObject();
}
else if ($Type == "Hall Fee") {
$HallFee = new HallFee();
$HallFee->setID($PID);
$getHallFee = $_PaymentBAO->getHallFee($HallFee)->getResultObject();
}
else if ($Type == "Others Fee") {
$Others = new OthersFee();
$Others->setID($PID);
$getOthersFee = $_PaymentBAO->getOthersFee($Others)->getResultObject();
}
?>