<?php

include UTILITY . 'class.util.inc';
include COMMON . 'class.common.budget.inc';

class ManageBudgetInformationDAO {

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

	public function createBudgetInfromation($budgetSubsector) {
		$budgetSectorId = $budgetSubsector->getBudgetSectorId();
		$startDate = $budgetSubsector->getStartDate();
		$endDate = $budgetSubsector->getEndDate();
		$budgetProgress = $budgetSubsector->getBudgetProgress();
		$description = $budgetSubsector->getBudgetDescription();
		$amount = $budgetSubsector->getBudgetAmount();

		$sql = "INSERT INTO 
		budget_subsector(
			budget_sector_id, 
			start_date, 
			end_date, 
			budget_progress, 
			description,
			amount
		) VALUES (
			'$budgetSectorId', 
			'$startDate', 
			'$endDate', 
			'$budgetProgress', 
			'$description',
			'$amount'
		)";

		$sql = $this->_db->doQuery($sql);
		$result = new Result();
		$result->setIsSuccess(1);
		$result->setResultObject($sql);

		return $result;
	}



	public function updateBudgetInfromation($budgetIformation) {
		$budgetSubsectorId = $budgetIformation->getBudgetSubsectorId();
		$startDate = $budgetIformation->getStartDate();
		$endDate = $budgetIformation->getEndDate();
		$budgetProgress = $budgetIformation->getBudgetProgress();
		$description = $budgetIformation->getBudgetDescription();
		$amount = $budgetIformation->getBudgetAmount();

		$sql = "UPDATE budget_subsector SET  
			start_date = '$startDate', 
			end_date = '$endDate', 
			budget_progress = '$budgetProgress', 
			description = '$description',
			amount = '$amount'
		WHERE budget_subsector_id = '$budgetSubsectorId';";

		$sql = $this->_db->doQuery($sql);

		$result = new Result();
		$result->setIsSuccess(1);
		$result->setResultObject($sql);
		return $result;
	}

	public function getBudgetInformationById($budgetSubsectorId) {
		$sql = "SELECT * FROM budget_subsector WHERE budget_subsector_id = '$budgetSubsectorId';";

		$this->_db->doQuery($sql);
		$row = $this->_db->getTopRow();
		
		$budgetSubsector = new BudgetSubsector();
		$budgetSubsector->setBudgetSubsectorId($row['budget_subsector_id']);
		$budgetSubsector->setBudgetSectorId($row['budget_sector_id']);
		$budgetSubsector->setStartDate($row['start_date']);
		$budgetSubsector->setEndDate($row['end_date']);
		$budgetSubsector->setBudgetProgress($row['budget_progress']);
		$budgetSubsector->setBudgetDescription($row['description']);
		$budgetSubsector->setBudgetAmount($row['amount']);
		
		$result = new Result();
		$result->setIsSuccess(1);
		$result->setResultObject($budgetSubsector);

		return $result;

	}	

	public function getAllBudgetSubsector() {
		$sql = "SELECT budget_subsector.*, budget_sector.* 
		FROM budget_subsector INNER JOIN budget_sector ON 
		budget_sector.budget_sector_id = budget_subsector.budget_sector_id";

		$this->_db->doQuery($sql);
		$rows = $this->_db->getAllRows();

		$budgteSubsectorList = [];

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
			$budgteSubsectorList[] = $budgetSubsector;
		}

		$result = new Result();
		$result->setIsSuccess(1);
		$result->setResultObject($budgteSubsectorList);

		return $result;

	}
}