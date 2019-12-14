<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_PRODUCT.'dao/class.create_productdao.inc';


/*
	Payment Business Object 
*/
Class Create_ProductBAO{

	private $_DB;
	private $_Create_ProductDAO;

	function Create_ProductBAO(){

		$this->_Create_ProductDAO = new Create_ProductDAO();

	}



	public function getAllProductCategorys(){

		$Result = new Result();	
		$Result = $this->_Create_ProductDAO->getAllProductCategorys();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in PaymentDAO.getAllProductCategorys()");		

		return $Result;
	}

		public function createProduct($create_product){

		$Result = new Result();	
		$Result = $this->_Create_ProductDAO->createProduct($create_product);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in create_productDAO.createProduct()");		

		return $Result;

	
	}

	//create Product funtion with the Product object
	public function editProduct($Product){

		$Result = new Result();	
		$Result = $this->_Create_ProductDAO->editProduct($Product);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in create_productDAO.editProduct()");		

		return $Result;

	
	}

	public function updateProduct($Product){

		$Result = new Result();	
		$Result = $this->_Create_ProductDAO->updateProduct($Product);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in create_productDAO.updateProduct()");		

		return $Result;
	}


//delete an existing Product
	public function deleteProduct($Product){

		$Result = new Result();	
		$Result = $this->_Create_ProductDAO->deleteProduct($Product);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in create_productDAO.deleteProduct()");		

		return $Result;

	}
	
	
	


	

	
}

?>