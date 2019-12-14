<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_PRODUCT.'bao/class.create_productbao.inc';

$_CREATE_PRODUCTBAO = new create_productBAO();
$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();


if(isset($_POST['add']))
{
	 $create_product = new Products();

	 $create_product->setID(Util::getGUID());
     $create_product->setName($_DB->secureInput($_POST['txtName']));
     
     if(isset($_POST['selectedCategory'])){ 

		$create_product->setCategoryID($_POST['selectedCategory']);
	}

     $create_product->setPrice($_DB->secureInput($_POST['txtPrice']));
     $create_product->setOfferedCredit($_DB->secureInput($_POST['txtCredit']));

	

	
	// //if(isset($_POST['txtAddPicture'])){
	
	// //$create_product->setPicture($_DB->secureInput($_FILES['txtAddPicture']['name'])) ;
	// $image = $_FILES['txtAddPicture']['name'];
	// $create_product->setPicture( $image);
	// if (move_uploaded_file($_FILES['txtAddPicture']['tmp_name'], $target)) {
			
	// 	}

	//}	
    $filename = $_FILES['image']['name'];
    $create_product->setPicture($_DB->secureInput($filename));
	$_CREATE_PRODUCTBAO -> createProduct($create_product);
	//$create_product->setPicture("image");
	$filename = $_FILES['image']['name'];
	$tempname = $_FILES['image']['tmp_name'];
	// if(isset($filename)){
	// 	if(!empty($filename)){
	// 		$location = "images/";
	// 		if (move_uploaded_file($tempname, $location.$filename)) {
	// 			//$msg = "Image uploaded successfully";
	// 			echo "Image uploaded successfully";
	// 		}
	// 	}
	// }

	$target = "./resources/img/product_images/".basename($_FILES['image']['name']);
	//$target = "./modules/products/ui/blade/images/".basename($_FILES['image']['name']);

	if (move_uploaded_file($_FILES['image']['tmp_name'], $target)) {
			
		}
	


	
	//echo  var_dump($image);
	//$image = $_FILES['image']['name'];
   	 //$_PaymentBAO->UpdateDue($create_product);
	// $_PaymentBAO->createPayment($create_product);
	// $_PaymentBAO->Paymentlog($create_product);	 
}
//deleting an existing product
if(isset($_POST['deleteProduct']))
{

	$Product = new Products();	
	$Product->setID($_POST['pID']);	
	$_CREATE_PRODUCTBAO->deleteProduct($Product); //reading the Product object from the result object

	header("Location:".PageUtil::$CREATE_PRODUCT);
}

/* reading an existing Product information */
if(isset($_POST['editProducts']))
{
	$Product = new Products();	
	$Product->setID($_POST['pID']);		
	//$Product= setID("{1A53D0E6-A580-4EA9-A2F9-B35CF92DDD01}");
	$getROW = $_CREATE_PRODUCTBAO->editProduct($Product)->getResultObject(); //reading the Product object from the result object
}

/*updating an existing Product information*/
if(isset($_POST['update']))
{
	$Product = new Products();	

    $Product->setID ($_POST['eProductID']);
    $Product->setName( $_POST['txtName'] );
    $Product->setCategoryID($_POST['selectedCategory']);
    $Product->setPrice($_POST['txtPrice']);
    $Product->setOfferedCredit($_POST['txtCredit']);
	
	$filename = $_FILES['image']['name'];
    $Product->setPicture($_DB->secureInput($filename));

    $_CREATE_PRODUCTBAO->updateProduct($Product);

    //moving the image file to the folder
	$filename = $_FILES['image']['name'];
	$tempname = $_FILES['image']['tmp_name'];
	
	//$target = "./modules/products/ui/blade/images/".basename($_FILES['image']['name']);
	$target = "./resources/img/product_images/".basename($_FILES['image']['name']);

	if (move_uploaded_file($_FILES['image']['tmp_name'], $target)) {
			
		}

	header("Location:".PageUtil::$CREATE_PRODUCT);
}


/*

if (isset($_POST['upload'])) {
		$target = "images/".basename($_FILES['image']['name']);


		$image = $_FILES['image']['name'];
		$book_name = $_POST['book_name'];
		}*/






//echo '<br> log:: exit blade.create_product.php';

?>