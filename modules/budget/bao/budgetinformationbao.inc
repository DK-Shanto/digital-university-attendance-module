<?php  

include MODULES_BUDGET . 'dao/budgetinformationdao.inc';

class BudgetInformationBAO
{
	private $_budgetInformationDAO;

	public function __construct(){
		$this->_budgetInformationDAO = new BudgetInformationDAO();
	}

	public function getAllBudgetSector() {
		$result = $this->_budgetInformationDAO->getAllBudgetSector();
		if ($result->getIsSuccess()) {
			return $result;
		}
		return null;
	}

	public function getAllBudgetSubsectorById($budgetSectorId) {
		$result = $this->_budgetInformationDAO->getAllBudgetSubsectorById($budgetSectorId);
		if ($result->getIsSuccess()) {
			return $result;
		}
		return null;
	}
}