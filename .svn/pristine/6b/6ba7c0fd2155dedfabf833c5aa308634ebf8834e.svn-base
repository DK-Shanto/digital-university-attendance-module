<?php include MODULES_BUDGET . 'ui/blade/view.budgetinformation.blade.inc'; ?>

<div class="container">
	<div class="panel panel-default">
		<div class="panel-heading">
			<h4>Budget Information</h4>
		</div>
		<div class="panel-body">
			<table class="table table-bordered">
				<thead>
					<tr>
						<th>Serial No.</th>
						<th>Budget Sector Name</th>
					</tr>
				</thead>
				<tbody>
					<?php
						if (!is_null($allBudgetSector)) {
							$i = 0;
							$rows = $allBudgetSector->getResultObject();
							foreach ($rows as $row) {
					?>
								<tr>
									<td><?php echo ++$i; ?></td>
									<td>
										<a href="budgetinformation.php?v=<?php echo $row->getBudgetSectorId(); ?>"><?php echo $row->getBudgetSectorName(); ?></a>
									</td>
								</tr>
					<?php
							}
						}
					?>
				</tbody>
			</table>
		</div>
		<div class="panel-body">
			<?php

				if (isset($allBudgetSubsectorByIdResult) && !is_null($allBudgetSubsectorByIdResult)) {
					$rows = $allBudgetSubsectorByIdResult->getResultObject();
			?>
				<table class="table table-bordered">
				<tr>

					<th>Budget Sector</th>
					<th>Budget Amount</th>
					<th>Start Date</th>
					<th>End Date</th>
					<th>Budget Progress</th>
					<th>Budget Description</th>
				</tr>
				<?php 
		
					foreach ($rows as $row) {
				?>
						<tr>
	
							<td><?php echo $row->getBudgetSubsectorName(); ?></td>
							<td><?php echo $row->getBudgetAmount(); ?></td>
							<td><?php echo $row->getStartDate(); ?></td>
							<td><?php echo $row->getEndDate(); ?></td>
							<td style="width:40px"><?php echo $row->getBudgetProgress().'%'; ?></td>
							<td style="width:500px"><?php echo $row->getBudgetDescription(); ?></td>
						</tr>
				<?php
					}
				?>
				</table>
				
			<?php		
					
				}
			?>
		</div>
	</div>
</div>