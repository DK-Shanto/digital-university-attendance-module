<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_PRODUCT.'dao/class.productsdao.inc';

/*
	Payment Business Object 
*/
Class ProductsBAO{

	private $_DB;
	private $_Create_ProductDAO;

	function ProductsBAO(){

		$this->_ProductsDAO = new ProductsDAO();

	}


	public function searchProductByCat(){

		$Result = new Result();	
		$Result = $this->_ProductsDAO->searchProductByCat();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in productsDAO.searchProductByCat()");		

		return $Result;

	
	}

	public function getCategoryFromId($Cat){

		$Result = new Result();	
		$Result = $this->_ProductsDAO->getCategoryFromId($Cat);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ProductsDAO.getCategoryFromId()");		

		return $Result;

	
	}
	
	public function addToCart($cart){

		$Result = new Result();	
		$Result = $this->_ProductsDAO->addToCart($cart);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in create_productDAO.createProduct()");		

		return $Result;

	
	}
	


	

	
}


?>