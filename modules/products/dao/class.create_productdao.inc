<?php
// write dao object for each class
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.product.inc';
include_once COMMON.'class.common.user.inc';
Class Create_ProductDAO{

	private $_DB;
	private $_Cat;

	function Create_ProductDAO(){

		$this->_DB = DBUtil::getInstance();
	

	}


	public function getAllProductCategorys(){

		$ProductCategoryList = array();

		$this->_DB->doQuery("SELECT * FROM tbl_product_category order by Category ASC");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_ProductCategory = new ProductCategory();

		    $this->_ProductCategory->setID ( $row['ID']);
		    $this->_ProductCategory->setCategory( $row['Category'] );

		    $ProductCategoryList[]=$this->_ProductCategory;

		    }

		
		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($ProductCategoryList);

		return $Result;
	}

	public function createProduct($create_product){

		$ID=$create_product->getID();
		$Name=$create_product->getName();
		$Category=$create_product->getCategoryID();
		$Price=$create_product->getPrice();
		$Credit=$create_product->getOfferedCredit();
		$Picture=$create_product->getPicture();

		
		//$Creator=$_SESSION["globalUser"]->getID ();

		$SQL = "INSERT INTO tbl_products(ID,Name,CategoryID,Price,OfferedCredit,PictureAddress) 
				VALUES('$ID','$Name','$Category','$Price','$Credit','$Picture')";

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		

		return $Result;
	}

		public function editProduct($Product){
		
		
		$SQL = "SELECT * FROM tbl_products WHERE ID='".$Product->getID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Product from the database
		$row = $this->_DB->getTopRow();

		$this->_Product= new Products();

		//preparing the Product object
	    $this->_Product->setID ( $row['ID'] );
	    $this->_Product->setName( $row['Name'] );
	    $this->_Product->setCategoryID( $row['CategoryID'] );
		$this->_Product->setPrice( $row['Price'] );
		$this->_Product->setOfferedCredit( $row['OfferedCredit'] );



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Product);

		return $Result;
	}

	//update an Product object based on its 
	public function updateProduct($Product){

		$SQL = "UPDATE tbl_products SET Name='".$Product->getName()."',
				CategoryID = '".$Product->getCategoryID()."',
				Price='".$Product->getPrice()."',
				OfferedCredit='".$Product->getOfferedCredit()."',
				PictureAddress='".$Product->getPicture()."'
				WHERE ID='".$Product->getID()."'";

		//$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;




	}

	//delete an Product based on its id of the database
	public function deleteProduct($Product){


		$SQL = "DELETE from tbl_products where ID ='".$Product->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	}
?>