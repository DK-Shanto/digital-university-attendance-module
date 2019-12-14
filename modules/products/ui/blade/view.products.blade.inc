<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_PRODUCT.'bao/class.productsbao.inc';
$_PRODUCTSBAO = new productsBAO();
$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();


if(isset($_POST['searchByCat']))
{
	 $products = new Products();

     
     if(isset($_POST['selectedCategory'])){ 

		$products->setCategoryID($_POST['selectedCategory']);
	}


	$ResultSearch = $_PRODUCTSBAO -> searchProductByCat($products);
   	 //$_PaymentBAO->UpdateDue($create_product);
	// $_PaymentBAO->createPayment($create_product);
	// $_PaymentBAO->Paymentlog($create_product);	 
}

if (isset($_POST['addToCart']))
{
	$cart= new cart();

	$cart->setID(Util::getGUID());
	
	if(isset($_POST['productID'])){ 

		$cart->setProductID($_POST['productID']);
	}

	$_PRODUCTSBAO->addToCart($cart);

}









//echo '<br> log:: exit blade.create_product.php';

?>