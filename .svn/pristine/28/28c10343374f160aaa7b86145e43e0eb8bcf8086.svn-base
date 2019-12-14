<?php
include MODULES_BUDGET . 'dao/class.budgetdao.inc';

class BudgetBAO {
	
	private $_budgetDAO;

	public function __construct() {
		$this->_budgetDAO = new BudgetDAO();
	}

	public function addBudgetSector($objBudgetSector) {
		$result = $this->_budgetDAO->addBudgetSector($objBudgetSector);
		return $result;
	}

	public function getAllBudgetSector() {
		return $this->_budgetDAO->getAllBudgetSector();
	}

	public function getTopRow($objBudgetSector) {
		return $this->_budgetDAO->getTopRow($objBudgetSector);
	}

	public function updateBudgetSector($objBudgetSector) {
		return $this->_budgetDAO->updateBudgetSector($objBudgetSector);
	}

	public function deleteBudgetSector($budgetSectorId) {
		return $this->_budgetDAO->deleteBudgetSector($budgetSectorId);
	}
}