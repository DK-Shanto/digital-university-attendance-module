<?php
include_once 'blade/view.job_list.blade.inc';
include_once COMMON.'class.common.inc';
?>

<div class="panel panel-default">
    <div class="panel-heading">
    	Job Informations
    </div>
    <div id="form">
		<form method="post" class="form-horizontal">
			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtJobTitle">Job Title**:</label>
              	<div class="col-sm-6">
              		<input type="text" name="txtJobTitle" class="form-control" placeholder="Use a short and Unique Title" value="<?php 
					if(isset($_GET['edit'])) echo $globalJob->getTitle();  ?>" required/>
			  	</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtJobSubTitle">Job Sub-title**:</label>
              	<div class="col-sm-6">
              		<input type="text" name="txtJobSubTitle" class="form-control" placeholder="Give a short description of this job" value="<?php 
					if(isset($_GET['edit'])) echo $globalJob->getSubtitle();  ?>" required/>
			  	</div>
			</div>
	
			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtOrganization">Organization**:</label>
              	<div class="col-sm-6">  		
					<input type="text" name="txtOrganization" class="form-control" placeholder="Such as..Khulna University" value="<?php 
					if(isset($_GET['edit'])) echo $globalJob->getOrganization();  ?>" required/>
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtQualification">Qualification Needed**:</label>
              	<div class="col-sm-6">  		
					<input type="text" name="txtQualification" class="form-control" placeholder="Such as.. B.Sc Honours" value="<?php 
					if(isset($_GET['edit'])) echo $globalJob->getQualification();  ?>" required/>
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="selectGender">Eligible Gender**:</label>
              	<div class="col-sm-6">		
						   						    
						<select name="selectGender" class="form-control" id="select-from-roles" required>
							<?php
								if(isset($_GET['edit']))
								{
									$var='<option selected disabled>Select Gender</option>';
									if(strcmp($globalJob->getGender(),'Male')==0){
										$var = $var.'<option value="Male" selected>Male</option>
										<option value="Female">Female</option>
										<option value="Anyone">Anyone</option>';
									}
									elseif(strcmp($globalJob->getGender(),'Female')==0){
										$var = $var.'<option value="Male">Male</option>
										<option value="Female" selected>Female</option>
										<option value="Anyone">Anyone</option>';
									}
									else{
										$var = $var.'<option value="Male">Male</option>
										<option value="Female">Female</option>
										<option value="Anyone" selected>Anyone</option>';
									}
								}
								else{
									$var= '<option selected disabled>Select Gender</option>
											<option value="Male">Male</option>
											<option value="Female">Female</option>
											<option value="Anyone">Anyone</option>';
								}
								echo $var;
							?>
						</select>
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtAge">Age limit**:</label>
              	<div class="col-sm-6">	
					<input type="number" name="txtAge" class="form-control" placeholder="Enter between 20 - 50" min="20" max="50" value="<?php 
					if(isset($_GET['edit'])) echo $globalJob->getAgeLimit();  ?>" required/>
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="selectEmploymentType">Employment Type**:</label>
              	<div class="col-sm-6">		
						   						    
						<select name="selectEmploymentType" class="form-control" id="select-from-roles" required>
							<?php
								if(isset($_GET['edit']))
								{
									$var='<option selected disabled>Select Employment Type</option>';
									if(strcmp($globalJob->getEmploymentType(),'Part Time')==0){
										$var = $var.'<option value="Part Time" selected>Part Time</option>
													<option value="Full Time">Full Time</option>';
									}
									else{
										$var = $var.'<option value="Part Time">Part Time</option>
													<option value="Full Time" selected>Full Time</option>';
									}
								}
								else{
									$var = '<option selected disabled>Select Employment Type</option>
											<option value="Part Time">Part Time</option>
											<option value="Full Time">Full Time</option>';
								}
								echo $var;
							?>
						</select>	
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtVacancy">No of Vacancy**:</label>
              	<div class="col-sm-6">	
					<input type="number" name="txtVacancy" class="form-control" placeholder="Enter between 1 - 10" min="1" max="10" value="<?php 
					if(isset($_GET['edit'])) echo $globalJob->getNumberOfVacancy();  ?>" required/>
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtEmail">Contact Email**:</label>
              	<div class="col-sm-6">
			  		<input type="email" name="txtEmail" class="form-control" placeholder="Email Address" value="<?php 
					if(isset($_GET['edit'])) echo $globalJob->getEmail();  ?>" required/>
			  	</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtContactNumber">Contact Phone no**:</label>
              	<div class="col-sm-6">
			  		<input type="tel" name="txtContactNumber" class="form-control" placeholder="such as.. 0 1 * * * * * * * * *" maxlength="11" value="<?php 
					if(isset($_GET['edit'])) echo $globalJob->getContactNumber();  ?>" required/>
			  	</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtSalary">Salary(Approximate):</label>
              	<div class="col-sm-6">
			  		<input type="number" name="txtSalary" class="form-control" placeholder="Such as.. 65,000" maxlength="6" value="<?php 
					if(isset($_GET['edit'])) echo $globalJob->getSalary();  ?>"/>
			  	</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtLocation">Location Of this job(full details):</label>
              	<div class="col-sm-6">  		
					<input type="text" name="txtLocation" class="form-control" placeholder="Such as.. Gollamari,Khulna" value="<?php 
					if(isset($_GET['edit'])) echo $globalJob->getLocation();  ?>"/>
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtJobExperience">Job Experience(if needed):</label>
              	<div class="col-sm-6">	
					<input type="text" name="txtJobExperience" class="form-control" placeholder="Such as.. 2 years of Teaching" min="1" max="10" value="<?php 
					if(isset($_GET['edit'])) echo $globalJob->getJobExperience();  ?>"/>
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtLastDateOfApplication">Last Date of Application (--:--:--- 24:00)**:</label>
              	<div class="col-sm-6">	
					<input type="date" name="txtLastDateOfApplication" class="form-control" value="<?php 
					if(isset($_GET['edit'])) echo $globalJob->getLastDateOfApplication();  ?>" required/>
				</div>
			</div>
			
	        <div class="form-group">        
              	<div class="col-sm-offset-2 col-sm-10">
              		<?php
						if(isset($_GET['edit']))
						{
					?>
						<button type="submit" value="update" name="update">Update This Job</button>
					<?php
						}
						else
						{
					?>
						<button type="submit" value="save" name="save" disabled>Update This Job</button>
					<?php
						}
					?>
			    </div>
            </div> 
		</form>

	</div>

    <div class="panel-body over">
    	<table class="table table-bordered">
	    	<?php
				$Result = $_JobListBAO->getAllJobs();
				//if DAO access is successful to load all the users then show them one by one
				if($Result->getIsSuccess()){
					$JobList = $Result->getResultObject();
					?>
					<tr>
						<th>Title</th>
						<th>Sub-Title</th>
						<th>Publish Date</th>
						<th>Organization</th>
						<th>-----</th>
						<th>Gender</th>
						<th>Age Limit</th>
						<th>Vacancy</th>
						<th>Contact Email</th>
						<th>Contact Phone</th>
						<th>Salary</th>
						<th>Job Experience</th>
						<th>Job Location</th>
						<th>Last Application Date</th>
					</tr>
					<?php
					for($i = 0; $i < sizeof($JobList); $i++) {
						$Job = $JobList[$i];
						?>
					    <tr>
						    <td><?php echo $Job->getTitle(); ?></td>
						    <td><?php echo $Job->getSubtitle(); ?></td>
						    <td><?php echo $Job->getPublishDate(); ?></td>
						    <td><?php echo $Job->getOrganization(); ?></td>
						    <td>-----</td>
						    <td><?php echo $Job->getGender(); ?></td>
						    <td><?php echo $Job->getAgeLimit(); ?></td>
						    <td><?php echo $Job->getNumberOfVacancy(); ?></td>
						    <td><?php echo $Job->getEmail(); ?></td>
						    <td><?php echo $Job->getContactNumber(); ?></td>
						    <td><?php echo $Job->getSalary(); ?></td>
						    <td><?php echo $Job->getJobExperience(); ?></td>
						    <td><?php echo $Job->getLocation(); ?></td>
						    <td><?php echo $Job->getLastDateOfApplication(); ?></td>
						    <td>
						    <a href="?edit=<?php echo $Job->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a>
						    </td>
						    <td>
						    <a href="?del=<?php echo $Job->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a>
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