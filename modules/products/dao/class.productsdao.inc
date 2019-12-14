<?php
// write dao object for each class
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.product.inc';

Class ProductsDAO{

	private $_DB;
	private $_Cat;

	function ProductsDAO(){

		$this->_DB = DBUtil::getInstance();
	

	}


	public function searchProductByCat(){

		$ProductList = array();

		//$cat=$products->getCategoryID();

		$this->_DB->doQuery("SELECT * FROM tbl_products");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Product = new Products();

		    $this->_Product->setID ( $row['ID']);
		    $this->_Product->setName ( $row['Name']);
		    $this->_Product->setCategoryID( $row['CategoryID'] );
		    $this->_Product->setPrice( $row['Price'] );
		    $this->_Product->setOfferedCredit( $row['OfferedCredit'] );
		    $this->_Product->setPicture( $row['PictureAddress'] );



		    $ProductList[]=$this->_Product;

		    }

		
		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($ProductList);

		return $Result;
	}

	public function getCategoryFromId($cat){

		

		$SQL="SELECT Category FROM tbl_product_category WHERE ID= '$cat'";

		$SQL = $this->_DB->doQuery($SQL);		
		
		$row = $this->_DB->getTopRow();
		

		$this->_ProductCategory = new ProductCategory();

		//$this->_ItemCategory->setID ( $row['ID']);
		$this->_ProductCategory->setCategory( $row['Category'] );
		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_ProductCategory);

		return $Result;
	}

	public function addToCart($cart){

		$ID=$cart->getID();
		$Product=$cart->getProductID();
		$UserID=$_SESSION["globalUser"]->getID ();
		// $ID=$cart->getID();
		
		
		
		

		
		//$Creator=$_SESSION["globalUser"]->getID ();

		$SQL = "INSERT INTO tbl_cart(ID,ProductID,UserID,Datetime) 
				VALUES('$ID','$Product','$UserID',now())";

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		

		return $Result;
	}

	}
?>