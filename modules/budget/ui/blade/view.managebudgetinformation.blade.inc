<?php

include MODULES_BUDGET . 'bao/managebudgetinformationbao.inc';

$manageBudgetInformationBAO = new ManageBudgetInformationBAO();
$allBudgetSector = $manageBudgetInformationBAO->getAllBudgetSector();
$budgetInformationById = null;

if (isset($_POST['submit'])) {
	$budgetSectorId = $_POST['budget_sector_id'];
	$budgetAmount = $_POST['budget_amount'];
	$startdate = $_POST['start_date'];
	$endDate = $_POST['end_date'];
	$budgetProgress = $_POST['budget_progress'];
	$description = $_POST['description'];

	$budgetSubsector = new BudgetSubsector();
	$budgetSubsector->setBudgetSectorId($budgetSectorId);
	$budgetSubsector->setStartDate($startdate);
	$budgetSubsector->setEndDate($endDate);
	$budgetSubsector->setBudgetProgress($budgetProgress);
	$budgetSubsector->setBudgetDescription($description);
	$budgetSubsector->setBudgetAmount($budgetAmount);

	$manageBudgetInformationBAO->createBudgetInfromation($budgetSubsector);
}

if (isset($_POST['update'])) {
	$budgetSubsectorId = $_GET['edit'];
	$budgetAmount = $_POST['budget_amount'];
	$startdate = $_POST['start_date'];
	$endDate = $_POST['end_date'];
	$budgetProgress = $_POST['budget_progress'];
	$description = $_POST['description'];

	$budgetSubsector = new BudgetSubsector();
	$budgetSubsector->setBudgetSubsectorId($budgetSubsectorId);
	$budgetSubsector->setStartDate($startdate);
	$budgetSubsector->setEndDate($endDate);
	$budgetSubsector->setBudgetProgress($budgetProgress);
	$budgetSubsector->setBudgetDescription($description);
	$budgetSubsector->setBudgetAmount($budgetAmount);

	$manageBudgetInformationBAO->updateBudgetInfromation($budgetSubsector);
}

if (isset($_GET['edit'])) {
	$budgetSubsectorId = $_GET['edit'];
	$budgetSubsectorById = $manageBudgetInformationBAO->getBudgetInformationById($budgetSubsectorId);

	$budgetInformationById = is_null($budgetSubsectorById) ? null : $budgetSubsectorById->getResultObject();
}

$allBudgetSubsector = $manageBudgetInformationBAO->getAllBudgetSubsector();
