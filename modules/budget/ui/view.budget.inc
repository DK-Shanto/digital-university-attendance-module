<?php include MODULES_BUDGET . 'ui/blade/view.budget.blade.inc'; ?>

<div class="container">
	<h2 class="text-center">Budget Information</h2>
	<div class="row">
		 <div class="col-md-6 col-md-offset-3">
			<form action="budget.php" method="POST" class="form-horizontal">
				<div class="form-group">
					<label for="budget_sector_name" class="control-label">Budget Sector Name: </label>
					<input type="text" name="budget_sector_name"  placeholder="Please enter budget sector name" class="form-control" value="<?php if (isset($_GET['e'])) {
			$resultObject = $topRow->getResultObject();
			echo $resultObject->getBudgetSectorName();
		}  ?>">
					<input type="hidden" name="budget_sector_id" value="<?php if (isset($_GET['e'])) {
			$resultObject = $topRow->getResultObject();
			echo $resultObject->getBudgetSectorId();
		}  ?>">
				</div>
				<div class="form-group col-md-offset-5">
					<?php
						if (isset($_GET['e'])) {
							echo '<input type="submit" name="update" value="Update" class="btn btn-info">';
						} else {
							echo '<input type="submit" name="submit" value="Submit" class="btn btn-info">';
						}
					?>
				</div>
			</form>
		 </div>
	</div>
</div>

<div class="container">
	<table class="table table-bordered">
		
		<thead>
			<tr>
				<th>Serial No.</th>
				<th>Budget Sector Name</th>
				<th>Edit</th>
				<th>Delete</th>
			</tr>
		</thead>
		<tbody>
			<?php
				if (!empty($allBudgetSector)) {
					$i = 0;
					foreach ($allBudgetSector as $value) {
						$i++;
			?>
						<tr>
							<td><?php echo $i; ?></td>
							<td>
								<a href="budgetinformation.php?v=<?php echo $value['budget_sector_id'];; ?>"><?php echo $value['budget_sector_name']; ?></a>
							</td>
							<td>
								<p onclick="return confirm('sure to edit?');">
									<a href="budget.php?e=<?php echo $value['budget_sector_id']; ?>">edit</a>
								</p>
							</td>
							<td>
								<p onclick="return confirm('Sure to delete?');">
									<a href="budget.php?d=<?php echo $value['budget_sector_id']; ?>">delete</a>
								</p>
							</td>
						</tr>
			<?php
					}
				}
			?>
		</tbody>
	</table>
</div>
