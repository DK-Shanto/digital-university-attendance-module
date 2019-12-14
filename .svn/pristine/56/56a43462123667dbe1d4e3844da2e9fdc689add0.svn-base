<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_PRODUCT.'dao/class.checkoutdao.inc';


/*
	Payment Business Object 
*/
Class CheckoutBAO{

	private $_DB;
	private $_CheckoutDAO;

	function CheckoutBAO(){

		$this->_CheckoutDAO = new CheckoutDAO();

	}

	public function getCartItems(){

		$Result = new Result();	
		$Result = $this->_CheckoutDAO->getCartItems();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CheckoutDAO.getCartItems()");		

		return $Result;
	
	}

	public function deleteFromCart($Item){

		$Result = new Result();	
		$Result = $this->_CheckoutDAO->deleteFromCart($Item);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CheckoutDAO.deleteFromCart()");		

		return $Result;

	}

	public function getPayCredit(){

		$Result = new Result();	
		$Result = $this->_CheckoutDAO->getPayCredit();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CheckoutDAO.getPayCredit()");		

		return $Result;
	
	}

	public function updateBalanceCredit($TotalToPay){

		$Result = new Result();	
		$Result = $this->_CheckoutDAO->updateBalanceCredit($TotalToPay);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CheckoutDAO.updateBalanceCredit()");		

		return $Result;

	}

	// public function updateCredit($TotalCredit){

	// 	$Result = new Result();	
	// 	$Result = $this->_CheckoutDAO->updateCredit($TotalCredit);
		
	// 	if(!$Result->getIsSuccess())
	// 		$Result->setResultObject("Database failure in CheckoutDAO.updateCredit()");		

	// 	return $Result;

	// }

	

	public function deleteAllFromCart(){

		$Result = new Result();	
		$Result = $this->_CheckoutDAO->deleteAllFromCart();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CheckoutDAO.deleteAllFromCart()");		

		return $Result;

	}

}
?>