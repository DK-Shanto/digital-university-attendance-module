<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_CCA.'dao/class.ccauserdao.inc';

/*
	School Business Object
*/
Class CCAUSERBAO{

	private $_DB;
	private $_CCAUSERDAO;

	public function __construct(){

		$this->_CCAUSERDAO = new CCAUSERDAO();

	}

	//get all Schools value
	public function getCategories(){

		$Result = new Result();
		$Result = $this->_CCAUSERDAO->getCategories();

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CCAUSERDAO.getCategories()");

		return $Result;
	}
	public function getOrganizers(){

		$Result = new Result();
		$Result = $this->_CCAUSERDAO->getOrganizers();

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CCAUSERDAO.getOrganizers()");

		return $Result;
	}
	public function AddCatagory($ADDCAT){

		$Result = new Result();
		$Result = $this->_CCAUSERDAO->AddCatagory($ADDCAT);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CCAUSERDAO.getCategories()");

		return $Result;
	}
		public function Adddetails($ADD){

		$Result = new Result();
		$Result = $this->_CCAUSERDAO->Adddetails($ADD);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CCAUSERDAO.getCategories()");

		return $Result;
	}
	public function SearchEvent($query){
		$Result = new Result();
		$Result = $this->_CCAUSERDAO->SearchEvent($query);

		//if(!$Result->getIsSuccess())
		//	$Result->setResultObject("Database failure in CCADAO.SearchEvent()");
	}

	public function SearchEvent1($query){
		$Result = new Result();
		$Result = $this->_CCAUSERDAO->SearchEvent1($query);

		//if(!$Result->getIsSuccess())
		//	$Result->setResultObject("Database failure in CCADAO.SearchEvent()");
	}



}

//echo '<br> log:: exit the class.schoolbao.php';

?>
