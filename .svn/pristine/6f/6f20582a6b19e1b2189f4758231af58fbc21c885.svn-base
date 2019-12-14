<?php  include MODULES_BUDGET . 'ui/blade/view.managebudgetinformation.blade.inc'; ?>

<div class="container">
	<div class="panel panel-default">
		<div class="panel-heading">
			<h4>Manage Budget Information</h4>
		</div>
		<div class="panel-body">
			<div class="col-md-offset-3 col-md-6">
				<form action="" method="POST">
					<div class="form-group">
						<label for="budget_sector_id">Budget Sector:</label>
						<select name="budget_sector_id" <?php echo isset($_GET['edit']) ? 'disabled' : ''; ?> class="form-control">
							<option>Please select budget sector</option>
							<?php 
								if (!is_null($allBudgetSector)) {
									$rows = $allBudgetSector->getResultObject();
									foreach ($rows as $row) {
										if (!is_null($budgetInformationById) && $row->getBudgetSectorId() == $budgetInformationById->getBudgetSectorId()) {
											echo '<option value="' . $row->getBudgetSectorId() . '" selected>' . $row->getBudgetSectorName() . '</option>';
										} else {
											echo '<option value="' . $row->getBudgetSectorId() . '">' . $row->getBudgetSectorName() . '</option>';
										}
									}
								}
							?>
						</select>
					</div>
					<div class="form-group">
						<label for="budget_amount">Budget Amount:</label>
						<input type="text" name="budget_amount" value="<?php echo isset($_GET['edit']) ? $budgetInformationById->getBudgetAmount() : ''; ?>" placeholder="Budget Amount" class="form-control">
					</div>
					<div class="form-group">
						<label for="start_date">Start Date:</label>
						<input type="date" name="start_date" value="<?php echo isset($_GET['edit']) ? $budgetInformationById->getStartDate() : ''; ?>" placeholder="" class="form-control">
					</div>
					<div class="form-group">
						<label for="end_date">End Date:</label>
						<input type="date" name="end_date" value="<?php echo isset($_GET['edit']) ? $budgetInformationById->getEndDate() : ''; ?>" placeholder="" class="form-control">
					</div>
					<div class="form-group">
						<label for="budget_progress">Budget Progress:</label>
						<input type="number" name="budget_progress" value="<?php echo isset($_GET['edit']) ? $budgetInformationById->getBudgetProgress() : ''; ?>" placeholder="Budget Progress" class="form-control">
					</div>
					<div class="form-group">
						<label for="description">Description:</label>
						<textarea name="description" placeholder="Description" class="form-control">
							<?php echo isset($_GET['edit']) ? $budgetInformationById->getBudgetDescription() : ''; ?>
						</textarea>
					</div>
					
					<?php 
						if (isset($_GET['edit'])) {
					?>
							<div>
								<button type="submit" name="update" class="btn btn-primary">
									Update
								</button>
							</div>
					<?php
						} else {
					?>
							<div class="form-group">
								<button type="submit" name="submit" class="btn btn-primary">ADD</button>
							</div>
					<?php		
						}
					?>
				</form>
			</div>
		</div>
	</div>
</div>
<div class="panel panel-default">
	<div class="panel-body">
		<table class="table table-bordered">
			<tr>
				<th>Serial No.</th>
				<th>Budget Sector</th>
				<th>Budget Ammount</th>
				<th>Start Date</th>
				<th>End Date</th>
				<th>Budget Progress</th>
				<th>Budget Description</th>
			</tr>
			<?php
				if (!is_null($allBudgetSubsector)) {
					$rows = $allBudgetSubsector->getResultObject();

					$i = 0;
					foreach ($rows as $row) {
			?>
						<tr>
							<td><?php echo ++$i; ?></td>
							<td><?php echo $row->getBudgetSubsectorName(); ?></td>
							<td><?php echo $row->getBudgetAmount(); ?></td>
							<td><?php echo $row->getStartDate(); ?></td>
							<td><?php echo $row->getEndDate(); ?></td>
							<td><?php echo $row->getBudgetProgress()."%"; ?></td>
							<td style="width:500px"><?php echo $row->getBudgetDescription(); ?></td>
							<td>
								<a href="?edit=<?php echo $row->getBudgetSubsectorId(); ?>" onclick="return alert('Sure to edit?');">Update</a>
							</td>
						</tr>
			<?php
					}
				}
			?>
		</table>
	</div>
</div>