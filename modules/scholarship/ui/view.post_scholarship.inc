<?php

include_once 'blade/view.post_scholarship.blade.inc';
include_once COMMON.'class.common.inc';


?>


<div class="panel panel-default">
    
    <div class="panel-heading">New Scholarship Information</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtScholarshipTitle">Scholarship Title:</label>
              	<div class="col-sm-6">
              		<input type="text" name="txtscholarshipTitle" class="form-control" placeholder="Use a short and Unique Title" value="<?php 
					if(isset($_GET['edit'])) echo $globalScholarship->getTitle();  ?>" required/>
			  	</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtScholarshipSubTitle">Scholarship Description:</label>
              	<div class="col-sm-6">
              		<textarea type="text" id="txtScholarshipSubTitle" name="txtScholarshipSubTitle" class="form-control" placeholder="Give a short description of this Scholarship" rows="5" text-align="left" required>
              		<?php if(isset($_GET['edit'])) echo $globalScholarship->getSubtitle();  ?></textarea>
			  	</div>
			</div>
			
			<script>
				function myFunction() {
				    document.getElementById("txtScholarshipSubTitle").value = "Fifth Avenue, New York City";
				}
			</script>
			<div class="form-group">
              	<label class="control-label col-sm-4" for="selectCatagory">Category:</label>
              	<div class="col-sm-6">	

							<?php
							$Result = $_CatagoryBAO->getAllCatagorys();
							if ($Result->getIsSuccess()){
								$CatagoryList = $Result->getResultObject();

							}
							?>
							<select name="selectCatagory" class="form-control" required>
								<option selected disabled>Select Catagory</option>
								<?php
								for ($i = 0; $i<sizeof($CatagoryList); $i++){
									$Catagory = $CatagoryList[$i];
									?>
									<?php
									if (!isset($_GET['edit'])){

										?>
										<option value="<?php echo $Catagory->getShortName();?>" > <?php echo $Catagory->getCatagoryName(); ?> 
										</option>
										<?php
									}
									if (isset($_GET['edit'])){

										if ($globalScholarship->getCategory() == $Catagory->getShortName() ){
											?>
											<option selected value = "<?php echo $Catagory->getShortName();?>" > 
												<?php echo $Catagory->getCatagoryName();?> 
											</option>
											<?php
										}
										else {

											?>
											<option value="<?php echo $Catagory->getShortName();?>" > <?php echo $Catagory->getCatagoryName(); ?> 
											</option>
											<?php
										}	
									}
								}
								?>	
							</select>
				</div>
			</div>	
	
			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtOrganization">Organization:</label>
              	<div class="col-sm-6">  		
					<input type="text" name="txtOrganization" class="form-control" placeholder="Such as..Khulna University" 
					value="<?php if(isset($_GET['edit'])) echo $globalScholarship->getOrganization();  ?>" required/>
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="selectGender">Eligible Gender:</label>
              	<div class="col-sm-6">		
						   						    
						<select name="selectGender" class="form-control" id="select-from-roles" required>
							<option selected disabled>Select Gender</option>
							<option value="Male">Male</option>
							<option value="Female">Female</option>
							<option value="Anyone">Anyone</option>
							<?php
							if(isset($_GET['edit'])){
							?>
							<option selected value= "<?php echo $globalScholarship->getGender(); ?>">
								<?php echo $globalScholarship->getGender(); ?></option>
							<?php
							}
							?>

						</select>	
				</div>
			</div>


			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtAge">Age limit:</label>
              	<div class="col-sm-6">	
					<input type="number" name="txtAge" class="form-control" placeholder="Enter between 20 - 50" min="20" max="50" 
					value="<?php 
					if(isset($_GET['edit'])) echo $globalScholarship->getAgeLimit();  ?>" required/>
				</div>
			</div>

			

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtEmail">Email:</label>
              	<div class="col-sm-6">
			  		<input type="email" name="txtEmail" class="form-control" placeholder="Email Address"
			  		value="<?php 
					if(isset($_GET['edit'])) echo $globalScholarship->getEmail();  ?>" required/>
			  	</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtContactNumber">Mobile No:</label>
              	<div class="col-sm-6">
			  		<input type="tel" name="txtContactNumber" class="form-control" placeholder="such as.. 0 1 * * * * * * * * *" maxlength="11"
			  		value="<?php 
					if(isset($_GET['edit'])) echo $globalScholarship->getContactNumber();  ?>" required/>
			  	</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtAmount">Scholarship Amount:</label>
              	<div class="col-sm-6">
			  		<input type="number" name="txtAmount" class="form-control" placeholder="Enter the Amount" maxlength="6"
			  		value="<?php 
					if(isset($_GET['edit'])) echo $globalScholarship->getScholarshipAmount();  ?>" required/>
			  	</div>
			</div>

			

			

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtLastDateOfApplication">Last Date of Application (--:--:--- 24:00):</label>
              	<div class="col-sm-6">	
					<input type="date" name="txtLastDateOfApplication" class="form-control"
					value="<?php 
					if(isset($_GET['edit'])) echo $globalScholarship->getLastDateOfApplication();  ?>" required/>
				</div>
			</div>
			
	        <div class="form-group">        
              	<div class="col-sm-offset-2 col-sm-10">
					<?php
						if(isset($_GET['edit']))
						{
					?>
							<button type="submit" value="update" name="update">update</button>
							<?php
						}
						else
						{
							?>
							<button type="submit" value="save" name="save">submit</button>
							<?php
						}
							?>
			    </div>
            </div> 
		</form>

	</div>
	<div id="toastME">Some Text Message..</div>
	</div>

	<div class="panel-body">
		<table class="table table-bordered">
			<?php

			$Result = $_ScholarshipBAO->getAllScholarships();

			//if DAO access is successful to load all the users then show them one by one
			if($Result->getIsSuccess()){

				$ScholarshipList = $Result->getResultObject();
			?>
				<tr>
					<th>Scholarship Title</th>
					<th>Description</th>
					<th>Category</th>
					<th>Organization</th>
					<th>Published Date</th>
					<th>Eligible Gender</th>
					<th>Age limit</th>
					<th>Contact Email</th>
					<th>Contact No</th>
					<th>Amount</th>
					<th>Last Date</th>


				</tr>
				<?php
				for($i = 0; $i < sizeof($ScholarshipList); $i++) {
					$Scholarship = $ScholarshipList[$i];
					?>
				    <tr>
					    <td><?php echo $Scholarship->getTitle(); ?></td>
					    <td><?php echo $Scholarship->getSubtitle(); ?></td>
					    <td><?php echo $Scholarship->getCategory(); ?></td>
					    <td><?php echo $Scholarship->getOrganization(); ?></td>
					    <td><?php echo $Scholarship->getPublishDate(); ?></td>
					    <td><?php echo $Scholarship->getGender(); ?></td>
					    <td><?php echo $Scholarship->getAgeLimit(); ?></td>
					    <td><?php echo $Scholarship->getEmail(); ?></td>
					    <td><?php echo $Scholarship->getContactNumber(); ?></td>
					    <td><?php echo $Scholarship->getScholarshipAmount(); ?></td>
					    <td><?php echo $Scholarship->getLastDateOfApplication(); ?></td>
					    <td>
					    <a href="?edit=<?php echo $Scholarship->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a>
					    </td>
					    <td>
					    <a href="?del=<?php echo $Scholarship->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a>
					    </td>

				    </tr>

			    <?php

				}

			}
			else{

				echo $Result->getResultObject(); //giving failure message
			}

			?>
		</table>
	</div>

</div>