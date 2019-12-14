<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_PAYMENT.'bao/class.paymentbao.inc';
$_PaymentBAO = new PaymentBAO();
$_DB = DBUtil::getInstance();
$getRow =$_PaymentBAO->getRechargeLog()->getResultObject();
date_default_timezone_set("Asia/Dhaka");
$date = date('Y/m/d h:i:s', time());
/* saving the recharge*/
if(isset($_POST['recharge']))
{
	 $Recharge = new Recharge();	
	 $Recharge->setID(Util::getGUID());
	 $Recharge->setDate($date);
     $Recharge->setEmail($_DB->secureInput($_POST['email']));
     $Recharge->setAmount($_DB->secureInput($_POST['amount']));
	 $_PaymentBAO->setRechargeAmount($Recharge);
	 header("Location: recharge.php");
}
?>
