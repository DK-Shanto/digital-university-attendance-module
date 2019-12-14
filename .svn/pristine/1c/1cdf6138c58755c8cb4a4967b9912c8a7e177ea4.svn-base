<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_PAYMENT.'bao/class.paymentbao.inc';
$_PaymentBAO = new PaymentBAO();
$_DB = DBUtil::getInstance();

$globalUser = '';
$globalUser = $_SESSION["globalUser"];
$User = new User();
$User->setID($globalUser->getID());
//
$getROW = $_PaymentBAO->getUserById($User)->getResultObject();
//getting balance
$getAccount = $_PaymentBAO->getAccountDetails($getROW)->getResultObject();
//getting discipline 
$Discipline = $getROW->getDiscipline();
//setting batch from university id
$UID = $getROW->getUniversityID();
//setting name
$name = $getROW->getFirstName();
$PaymentType = $_PaymentBAO->getPaymentType($getROW)->getResultObject();
