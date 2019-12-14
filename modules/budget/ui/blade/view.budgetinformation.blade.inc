<?php
include MODULES_BUDGET . 'bao/budgetinformationbao.inc';

$budgetInformationBAO = new BudgetInformationBAO();
$budgetSubsectorByIdResult = null;

if (isset($_GET['v']) && !empty($_GET['v'])) {
	$budgetSectorId = $_GET['v'];

	$allBudgetSubsectorByIdResult = $budgetInformationBAO->getAllBudgetSubsectorById($budgetSectorId);
}

$allBudgetSector = $budgetInformationBAO->getAllBudgetSector();