<?php
// write dao object for each class
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.product.inc';



Class CheckoutDAO{

	private $_DB;
	private $_Cat;

	function CheckoutDAO(){

		$this->_DB = DBUtil::getInstance();
		//$this->_Cat = new Payment();
		//$this->_Due = new Due();

	}

	public function getCartItems(){

		$CartList = array();
		$ID=$_SESSION["globalUser"]->getID ();

		$this->_DB->doQuery("select tbl_cart.ID, tbl_products.Name, tbl_products.Price,tbl_products.OfferedCredit,tbl_products.PictureAddress from tbl_cart,tbl_products where tbl_cart.ProductID=tbl_products.ID and tbl_cart.UserID='$ID'");
		$rows = $this->_DB->getAllRows();


		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Cart = new Products();
			


			$this->_Cart->setID ( $row['ID']);
		    $this->_Cart->setName ( $row['Name']);
		    $this->_Cart->setPrice( $row['Price'] );
		    $this->_Cart->setOfferedCredit( $row['OfferedCredit'] );
		    $this->_Cart->setPicture( $row['PictureAddress'] );

		    $CartList[]=$this->_Cart;
   
		}
		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CartList);

		return $Result;
	}

	public function deleteFromCart($Item){


		$SQL = "DELETE from tbl_cart where ID ='".$Item->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	public function getPayCredit(){

			$ID=$_SESSION["globalUser"]->getID ();

			$SQL = "select sum(tbl_products.Price) as TotalToPay, sum(tbl_products.OfferedCredit) as TotalCredit from tbl_cart,tbl_products where tbl_cart.ProductID=tbl_products.ID and tbl_cart.UserID='$ID'";

			

			$SQL = $this->_DB->doQuery($SQL);	

			$row = $this->_DB->getTopRow();

			$this->_Total = new TotalPayCredit();

		    $this->_Total->setTotalToPay( $row['TotalToPay']);
		    $this->_Total->setTotalCredit( $row['TotalCredit']);		
			
		 	$Result = new Result();
			$Result->setIsSuccess(1);
			$Result->setResultObject($this->_Total);

			return $Result;
		}

// here i have to update according to my module
	public function updateBalanceCredit($TotalToPay){

		$ID=$_SESSION["globalUser"]->getID ();
		$Email = $ID;
		$Amount=$TotalToPay->getTotalToPay();
		$Credit=$TotalToPay->getTotalCredit();
		$SQL2 = "SELECT Amount FROM pms_recharge WHERE Email='$Email'";
		$SQL2 = $this->_DB->doQuery($SQL2);
		$row = $this->_DB->getTopRow();
		$amount = $row['Amount'] - $Amount;

		$SQL3 = "UPDATE pms_recharge SET Amount ='$amount' WHERE Email='$Email'";
		$SQL3 = $this->_DB->doQuery($SQL3);
		//getting user id using email
		$SQL4 = "SELECT UniversityID FROM ums_user WHERE Email='$Email'";
		$SQL4 =  $this->_DB->doQuery($SQL4);
		$row1 = $this->_DB->getTopRow();
		$UID = $row1['UniversityID'];
		date_default_timezone_set("Asia/Dhaka");
		$Date = date('Y/m/d h:i:s', time());
		var_dump($Date);
		$Type = "Product";
		$IID = Util::getGUID();
		$PID = Util::getGUID();
		$SQL = "INSERT pms_payment_type VALUES('$IID', '$PID' ,'$UID','$Type','$Date')";
		$SQL = $this->_DB->doQuery($SQL);
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL3);

		return $Result;

		//payment type

	}

	public function deleteAllFromCart(){

		$ID=$_SESSION["globalUser"]->getID ();
		$SQL = "DELETE from tbl_cart where UserID ='".$ID."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

?>