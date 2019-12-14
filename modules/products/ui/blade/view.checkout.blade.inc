<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_PRODUCT.'bao/class.checkoutbao.inc';

$_CheckoutBAO = new CheckoutBAO();
$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();


// if(isset($_POST['pay']))
// {
 	// $Payment = new PayLogs();

	 
//      $Payment->setAmount($_DB->secureInput($_POST['txtPayAmount']));

//      if(isset($_POST['selectedCategory'])){ 

// 		$Payment->setCategoryID($_POST['selectedCategory']);
// 	}

//    	 $_PaymentBAO->UpdateDue($Payment);
// 	 $_PaymentBAO->createPayment($Payment);
// 	 $_PaymentBAO->Paymentlog($Payment);	 
// }

if(isset($_POST['deleteFromCart']))
{
	$delete = new Cart();
	$delete ->setID($_DB->secureInput($_POST['productID']));


	$_CheckoutBAO->deleteFromCart($delete);
}

if(isset($_POST['commit']))
{
	$totalToPay = new TotalPayCredit();
	$totalToPay ->setTotalToPay($_DB->secureInput($_POST['totalToPay']));
	$totalToPay ->setTotalCredit($_DB->secureInput($_POST['totalCredit']));

	$_CheckoutBAO->updateBalanceCredit($totalToPay);
	$_CheckoutBAO->deleteAllFromCart();

}

// if(isset($_POST['commit']))
// {
// 	$totalCredit = new TotalPayCredit();
// 	$totalCredit ->setTotalCredit($_DB->secureInput($_POST['totalCredit']));


// 	$_CheckoutBAO->updateCredit($totalCredit);//edit it
// }






//echo '<br> log:: exit blade.Payment.php';

?>