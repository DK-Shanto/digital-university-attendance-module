<?php
include UTILITY . 'class.util.inc';
include COMMON . 'class.common.budget.inc';

class BudgetDAO {

	private $_db;

	public function __construct() {
		$this->_db = DBUtil::getInstance();
	}

	public function addBudgetSector($objBudgetSector) {
		$budgetSectorName = $objBudgetSector->getBudgetSectorName();
		$sql = "INSERT INTO budget_sector(budget_sector_name) VALUES ('$budgetSectorName')";
		return $this->_db->doQuery($sql);;
	}

	public function getAllBudgetSector() {
		DBUtil::getInstance()->doQuery("SELECT * FROM budget_sector");
		return DBUtil::getInstance()->getAllRows();
	}

	public function getTopRow($objBudgetSector) {
		$budgetSectorId = $objBudgetSector->getBudgetSectorId();
		DBUtil::getInstance()->doQuery("SELECT * FROM budget_sector WHERE budget_sector_id = '$budgetSectorId'");
		$topRow = $this->_db->getTopRow();

		$budgetSector = new BudgetSector();
		$budgetSector->setBudgetSectorId($topRow['budget_sector_id']);
		$budgetSector->setBudgetSectorName($topRow['budget_sector_name']);

		$result = new Result();
		$result->setIsSuccess(1);
		$result->setResultObject($budgetSector);

		return $result;
	}

	public function updateBudgetSector($objBudgetSector) {
		$budgetSectorId = $objBudgetSector->getBudgetSectorId();
		$budgetSectorName = $objBudgetSector->getBudgetSectorName();
		$sql = "UPDATE budget_sector SET budget_sector_name='$budgetSectorName' WHERE budget_sector_id='$budgetSectorId'";
		return $this->_db->doQuery($sql);
	}

	public function deleteBudgetSector($budgetSectorId) {
		$sql = "DELETE FROM budget_sector WHERE budget_sector_id = '$budgetSectorId'";
		$sql = $this->_db->doQuery($sql);

		$result = new Result();
		$result->setIsSuccess(1);
		$result->setResultObject($sql);

		return $result;
	}
}