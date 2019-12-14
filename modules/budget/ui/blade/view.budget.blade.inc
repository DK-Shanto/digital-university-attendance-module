<?php
include MODULES_BUDGET . 'bao/class.budgetbao.inc';


if (isset($_POST['submit'])) {
	$budget_sector_name = $_POST['budget_sector_name'];
	
	$objBudgetSector = new BudgetSector();
	$objBudgetBAO = new BudgetBAO();

	$objBudgetSector->setBudgetSectorName($budget_sector_name);

	$result = $objBudgetBAO->addBudgetSector($objBudgetSector);
}


if (isset($_GET['e']) && !empty($_GET['e'])) {
	$budget_sector_id = $_GET['e'];
	
	$objBudgetSector = new BudgetSector();
	$objBudgetBAO = new BudgetBAO();

	$objBudgetSector->setBudgetSectorId($budget_sector_id);
	$topRow = $objBudgetBAO->getTopRow($objBudgetSector);
}

if (isset($_POST['update'])) {
	$budgetSectorId = $_POST['budget_sector_id'];
	$budgetSectorName = $_POST['budget_sector_name'];

	$budgetSector = new BudgetSector();
	$budgetSector->setBudgetSectorId($budgetSectorId);
	$budgetSector->setBudgetSectorName($budgetSectorName);

	$objBudgetBAO = new BudgetBAO();
	$objBudgetBAO->updateBudgetSector($budgetSector);
}

if (isset($_GET['d'])) {
	$budgetSectorId = $_GET['d'];

	$objBudgetBAO = new BudgetBAO();
	$objBudgetBAO->deleteBudgetSector($budgetSectorId);
}

$objBudgetBAO = new BudgetBAO();
$allBudgetSector = $objBudgetBAO->getAllBudgetSector();
