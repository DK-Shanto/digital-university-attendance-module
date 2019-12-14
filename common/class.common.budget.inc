<?php

class BudgetSector {

	private $budgetSectorId;
	private $budgetSectorName;

	public function setBudgetSectorId($budgetSectorId) {
		$this->budgetSectorId = $budgetSectorId;
	}

	public function setBudgetSectorName($budgetSectorName) {
		$this->budgetSectorName = $budgetSectorName;
	}

	public function getBudgetSectorId() {
		return $this->budgetSectorId;
	}

	public function getBudgetSectorName() {
		return $this->budgetSectorName;
	}
}

class BudgetSubsector {
	
	private $_budgetSubsectorId;
	private $_budgetSectorId;
	private $_budgetSubsectorName;
	private $_startDate;
	private $_endDate;
	private $_budgetProgress;
	private $_budgetDescription;
	private $_budgetAmount;

	public function setBudgetSubsectorId($budgetSubsectorId) {
		$this->_budgetSubsectorId = $budgetSubsectorId;
	}

	public function getBudgetSubsectorId() {
		return $this->_budgetSubsectorId;
	}

	public function setBudgetSectorId($budgetSectorId) {
		$this->_budgetSectorId = $budgetSectorId;
	}

	public function getBudgetSectorId() {
		return $this->_budgetSectorId;
	}

	public function setBudgetSubsectorName($budgetSubsectorName) {
		$this->_budgetSubsectorName = $budgetSubsectorName;
	}

	public function getBudgetSubsectorName() {
		return $this->_budgetSubsectorName;
	}

	public function setStartDate($startDate) {
		$this->_startDate = $startDate;
	}

	public function getStartDate() {
		return $this->_startDate;
	}

	public function setEndDate($endDate) {
		$this->_endDate = $endDate;
	}

	public function getEndDate() {
		return $this->_endDate;
	}

	public function setBudgetProgress($budgetProgress) {
		$this->_budgetProgress = $budgetProgress;
	}

	public function getBudgetProgress() {
		return $this->_budgetProgress;
	}

	public function setBudgetDescription($budgetDescription) {
		$this->_budgetDescription = $budgetDescription;
	}

	public function getBudgetDescription() {
		return $this->_budgetDescription; 
	}
	
	public function setBudgetAmount($budgetAmount) {
		$this->_budgetAmount = $budgetAmount;
	}

	public function getBudgetAmount() {
		return $this->_budgetAmount;
	}
}

