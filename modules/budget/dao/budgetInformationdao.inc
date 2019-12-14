<?php

include UTILITY . 'class.util.inc';
include COMMON . 'class.common.budget.inc';

class BudgetInformationDAO
{
	private $_db;

	public function __construct() {
		$this->_db = DBUtil::getInstance();
	}

	public function getAllBudgetSector() {
		$sql = "SELECT * FROM budget_sector";
		$this->_db->doQuery($sql);
		$rows = $this->_db->getAllRows();

		$budgetSectorList = [];
		foreach ($rows as $row) {
			$budgetSector = new BudgetSector();
			$budgetSector->setBudgetSectorId($row['budget_sector_id']);
			$budgetSector->setBudgetSectorName($row['budget_sector_name']);
			$budgetSectorList[] = $budgetSector;
		}

		$result = new Result();
		$result->setIsSuccess(1);
		$result->setResultObject($budgetSectorList);

		return $result;
	}

	public function getAllBudgetSubsectorById($budgetSectorId) {
		$sql = "SELECT budget_subsector.*, budget_sector.* 
		FROM budget_subsector INNER JOIN budget_sector ON 
		budget_sector.budget_sector_id = budget_subsector.budget_sector_id AND budget_subsector.budget_sector_id = '$budgetSectorId'";
		$this->_db->doQuery($sql);
		$rows = $this->_db->getAllRows();

		$budgetSubsectorList = [];

		foreach ($rows as $row) {
			$budgetSubsector = new BudgetSubsector();
			$budgetSubsector->setBudgetSubsectorId($row['budget_subsector_id']);
			$budgetSubsector->setBudgetSectorId($row['budget_sector_id']);
			$budgetSubsector->setBudgetSubsectorName($row['budget_sector_name']);
			$budgetSubsector->setStartDate($row['start_date']);
			$budgetSubsector->setEndDate($row['end_date']);
			$budgetSubsector->setBudgetProgress($row['budget_progress']);
			$budgetSubsector->setBudgetDescription($row['description']);
			$budgetSubsector->setBudgetAmount($row['amount']);

			$budgetSubsectorList[] = $budgetSubsector;	
		}

		

		$result = new Result();
		$result->setIsSuccess(1);
		$result->setResultObject($budgetSubsectorList);

		return $result;
	}
}