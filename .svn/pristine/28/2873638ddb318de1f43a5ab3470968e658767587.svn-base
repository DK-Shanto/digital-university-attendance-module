<?php

include_once 'blade/view.job_post.blade.inc';
include_once COMMON.'class.common.inc';

?>

<div class="panel panel-default">
    
    <div class="panel-heading">New Job Information</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtJobTitle">Job Title**:</label>
              	<div class="col-sm-6">
              		<input type="text" name="txtJobTitle" class="form-control" placeholder="Use a short and Unique Title" required/>
			  	</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtJobSubTitle">Job Sub-title**:</label>
              	<div class="col-sm-6">
              		<input type="text" name="txtJobSubTitle" class="form-control" placeholder="Give a short description of this job" required/>
			  	</div>
			</div>
	
			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtOrganization">Organization**:</label>
              	<div class="col-sm-6">  		
					<input type="text" name="txtOrganization" class="form-control" placeholder="Such as..Khulna University" required/>
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtQualification">Qualification Needed**:</label>
              	<div class="col-sm-6">  		
					<input type="text" name="txtQualification" class="form-control" placeholder="Such as.. B.Sc Honours" required/>
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="selectGender">Eligible Gender**:</label>
              	<div class="col-sm-6">		
						   						    
						<select name="selectGender" class="form-control" id="select-from-roles" required>
							<option selected disabled>Select Gender</option>
							<option value="Male">Male</option>
							<option value="Female">Female</option>
							<option value="Anyone">Anyone</option>
						</select>	
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtAge">Age limit**:</label>
              	<div class="col-sm-6">	
					<input type="number" name="txtAge" class="form-control" placeholder="Enter between 20 - 50" min="20" max="50" required/>
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="selectEmploymentType">Employment Type**:</label>
              	<div class="col-sm-6">		
						   						    
						<select name="selectEmploymentType" class="form-control" id="select-from-roles" required>
							<option selected disabled>Select Employment Type</option>
							<option value="Part Time">Part Time</option>
							<option value="Full Time">Full Time</option>
						</select>	
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtVacancy">No of Vacancy**:</label>
              	<div class="col-sm-6">	
					<input type="number" name="txtVacancy" class="form-control" placeholder="Enter between 1 - 10" min="1" max="10" required/>
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtEmail">Contact Email**:</label>
              	<div class="col-sm-6">
			  		<input type="email" name="txtEmail" class="form-control" placeholder="Email Address" required/>
			  	</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtContactNumber">Contact Phone no**:</label>
              	<div class="col-sm-6">
			  		<input type="tel" name="txtContactNumber" class="form-control" placeholder="such as.. 0 1 * * * * * * * * *" maxlength="11" required/>
			  	</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtSalary">Salary(Approximate):</label>
              	<div class="col-sm-6">
			  		<input type="number" name="txtSalary" class="form-control" placeholder="Such as.. 65,000" maxlength="6"/>
			  	</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtLocation">Location Of this job(full details):</label>
              	<div class="col-sm-6">  		
					<input type="text" name="txtLocation" class="form-control" placeholder="Such as.. Gollamari,Khulna"/>
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtJobExperience">Job Experience(if needed):</label>
              	<div class="col-sm-6">	
					<input type="text" name="txtJobExperience" class="form-control" placeholder="Such as..2 years of Teaching"/>
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtLastDateOfApplication">Last Date of Application (--:--:--- 24:00)**:</label>
              	<div class="col-sm-6">	
					<input type="date" name="txtLastDateOfApplication" class="form-control" required/>
				</div>
			</div>
			
	        <div class="form-group">        
              	<div class="col-sm-offset-2 col-sm-10">
					<button type="submit" value="request" name="request">Post This Job</button>
			    </div>
            </div> 
		</form>

	</div>
	<div id="toastME">Some Text Message..</div>
	</div>

</div>