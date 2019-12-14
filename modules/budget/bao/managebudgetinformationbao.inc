<?php

include MODULES_BUDGET . 'dao/managebudgetinformationdao.inc';

class ManageBudgetInformationBAO {

	private $_manageBudgetInformationDAO;

	public function __construct() {
		$this->_manageBudgetInformationDAO = new ManageBudgetInformationDAO();
	}

	public function getAllBudgetSector() {
		$result = $this->_manageBudgetInformationDAO->getAllBudgetSector();
		if ($result->getIsSuccess()) {
			return $result;
		}
		return null;
	}

	public function createBudgetInfromation($budgetSubsector) {
		$result = $this->_manageBudgetInformationDAO->createBudgetInfromation($budgetSubsector);
	}

	public function getAllBudgetSubsector() {
		$result = $this->_manageBudgetInformationDAO->getAllBudgetSubsector();
		if ($result->getIsSuccess()) {
			return $result;
		}
		return null;	
	}



	public function updateBudgetInfromation($budgetIformation){
		return $this->_manageBudgetInformationDAO->updateBudgetInfromation($budgetIformation);
	}

	public function getBudgetInformationById($budgetSubsectorId) {
		$result = $this->_manageBudgetInformationDAO->getBudgetInformationById($budgetSubsectorId);
		if ($result->getIsSuccess()) {
			return $result;
		}
		return null;
	}



} 